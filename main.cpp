#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>
#include "physicsObject.hpp"
#include "obstacle.hpp"
#include "gameFont.hpp"
#include "GameStates/home.hpp"
#include "balloon.hpp"
#include "UIElements/button.hpp"
#include "GameStates/gameState.hpp"
#include "resourceManager.hpp"
#include "GameStates/levels.hpp"
#include "levelSys.hpp"
#include "GameStates/playing.hpp"

const float needleHeight = 0.04f;
const float needleWidth = 0.08f;
const int WindowWidth = 1200;
const int WindowHeight = 800;
const float playerRadius = 0.025f;
bool fullScreen = false;



std::vector<Obstacle> spawnObstacles(std::vector<spawnData>& level){
    std::vector<Obstacle> result;
    for (int i = 0; i < level.size(); i++){
        Obstacle obstacle(needleWidth, needleHeight, level[i].color, level[i].Pattern);
        obstacle.y = level[i].y;
        obstacle.vx = level[i].vx;
        obstacle.x =  (WindowWidth-level[i].spawnTime * obstacle.vx);
        obstacle.Pattern = level[i].Pattern;
        result.push_back(obstacle);
    }
    return result;
    
}

int main(){

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window( sf::VideoMode( WindowWidth, WindowHeight), "Drift", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    std::vector<Obstacle> obstacles;
    Balloon player;

    GameFont fonts;
    fonts.arial.loadFromFile("fonts/ARIBLK.TTF");

    ResourceManager resourcemanager;

    resourcemanager.loadHomeBg();
    resourcemanager.loadButtonSprite();
    //home screen
    HomeGameState home(window, fonts, resourcemanager);

    Levels levels;
    levels.levels.resize(10);
    //menu
    LevelGameState menu(window, fonts, resourcemanager);

    resourcemanager.loadplayingBg();
    //playing screen
    PlayingGameState playingScreen(window, fonts, resourcemanager);

    //Game Over Screen
    sf::Text gameOver("Game Over", fonts.arial, 100);
    gameOver.setPosition(sf::Vector2f(300.00f, 300.00f));
    gameOver.setFillColor(sf::Color::White);

    //Pause Screen
    sf::Text pausedText("Paused", fonts.arial, 80);
    sf::Vector2f pausedTextSize = pausedText.getLocalBounds().getSize();
    pausedText.setOrigin(sf::Vector2f(pausedTextSize.x/2, pausedTextSize.y /2));
    pausedText.setPosition(sf::Vector2f(WindowWidth/2, WindowHeight/3));
    pausedText.setFillColor(sf::Color::White);
    
    double leftoverTime = 0.0;
    sf::Clock clock;
    

    GameState state = GameState::Home;
    

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if ( event.type == sf::Event::Resized){
                sf::View view(sf::FloatRect(0, 0, event.size.width, event.size.height));
                window.setView(view);
                home.resize();
                menu.resize();
                playingScreen.resize(obstacles, player);
            }
            if (event.type == sf::Event::KeyPressed){
                switch (event.key.code){
                case sf::Keyboard::Space:
                    if (state == GameState::Playing){player.isJump = true;}
                    break;
                case sf::Keyboard::F:
                    if (fullScreen){
                        window.create(sf::VideoMode(WindowWidth, WindowHeight), "Drift", sf::Style::Default, settings);
                        fullScreen = false;
                    }
                    else{
                        window.create(sf::VideoMode::getDesktopMode(), "Drift", sf::Style::Fullscreen, settings);
                        fullScreen = true;
                    }
                    break;
                default:
                    break;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    home.eventHandler.handleClick(event.mouseButton.x, event.mouseButton.y);
                    menu.eventHandler.handleClick(event.mouseButton.x, event.mouseButton.y);
                }
                
            }
        
        player.isShift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
        player.isCtrl = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
        }
        
        float dt = clock.restart().asSeconds();
        if (dt > 0.01){ dt = 0.008; leftoverTime=0;}

        switch (state){
            case GameState::Home: {
                home.show();
                if (home.requestState.has_value()){ 
                    if (home.requestState.value() == GameState::Menu){
                        state = GameState::Menu;
                    }
                    if (home.requestState.value() == GameState::LoadLevel){
                        menu.requestLevelNo = 1;
                        state = GameState::LoadLevel;
                    }
                    home.requestState.reset();
                }
                break;
            }

            case GameState::Menu:{
                menu.show();
                if (menu.requestState.has_value()){
                    state = GameState::LoadLevel;
                    menu.requestState.reset();
                }
                
                break;
            }
            
            case GameState::LoadLevel: {
                window.create(sf::VideoMode::getDesktopMode(), "Drift", sf::Style::Fullscreen, settings);
                fullScreen = true;
                leftoverTime = 0;
                levels.loadLevel(menu.requestLevelNo);
                obstacles = spawnObstacles(levels.levels[menu.requestLevelNo-1]);
                player.setRadius(playerRadius);
                player.setColor(sf::Color::Red);
                player.x = 100; 
                player.y = 300;
                player.vx = 0;
                player.vy = 0;
                player.ay = 500.00f;
                state = GameState::Playing;
                playingScreen.resize(obstacles, player);

                break;
            }
            
            case GameState::Playing: {
                playingScreen.show(dt, leftoverTime, obstacles, player);
                if (!playingScreen.alive){state = GameState::GameOver; playingScreen.alive=true;}
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){state = GameState::Paused;}
            
                break;
            }

            case GameState::Paused:{
                leftoverTime = 0;
                playingScreen.show(0, leftoverTime, obstacles, player);
                window.draw(pausedText);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){ state = GameState::Playing;}
                break;
            }

            case GameState::GameOver:{
                window.clear(sf::Color(71, 71, 71));
                window.draw(gameOver);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ state = GameState::Home; break;}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){state = GameState::LoadLevel;}
                break;
            }
        }

    
        window.display();
    }
    return 0;
}