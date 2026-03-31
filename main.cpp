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
#include "gameState.hpp"
#include "resourceManager.hpp"
#include "GameStates/levels.hpp"
#include "levelSys.hpp"
#include "GameStates/playing.hpp"
#include "GameStates/leveleditor.hpp"
#include "needle.hpp"

const int WindowWidth = 1200;
const int WindowHeight = 800;

int main(){

    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;

    sf::RenderWindow window( sf::VideoMode( WindowWidth, WindowHeight), "Drift", sf::Style::Close, settings);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(350, 100));
    // window.setVerticalSyncEnabled(true);


    GameFont fonts;
    fonts.arial.loadFromFile("fonts/ARIBLK.TTF");
    fonts.dracula.loadFromFile("fonts/IrishGrover.ttf");
    fonts.coolItalic.loadFromFile("fonts/IosevkaCharonMono-BoldItalic.ttf");


    ResourceManager resourcemanager;

    resourcemanager.loadHomeBg();
    resourcemanager.loadplayingBg();
    resourcemanager.loadhomeBalloon();
    resourcemanager.loadhomeCloud();
    resourcemanager.loadHomeNeedle();
    resourcemanager.loadNeedle();

    Game game(window, fonts, resourcemanager);
        
    double leftoverTime = 0.0;
    sf::Clock clock;
        

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if ( event.type == sf::Event::Resized){
                sf::View view(sf::FloatRect(0, 0, event.size.width, event.size.height));
                window.setView(view);
                game.states[game.currentState]->resize();
            }
            if(event.type == sf::Event::MouseMoved){
                game.states[game.currentState]->eventHandler.handleHover(event.mouseMove.x, event.mouseMove.y);
            }
            if (event.type == sf::Event::KeyPressed){
                switch (event.key.code){
                case sf::Keyboard::Space:
                    if (game.currentState == GameState::Playing){game.player.isJump = true;}
                    break;
                case sf::Keyboard::F:
                    if (game.fullScreen){
                        window.create(sf::VideoMode(WindowWidth, WindowHeight), "Drift", sf::Style::Default, settings);
                        game.fullScreen = false;
                    }
                    else{
                        window.create(sf::VideoMode::getDesktopMode(), "Drift", sf::Style::Fullscreen);
                        game.fullScreen = true;
                    }
                    window.setFramerateLimit(60);
                    break;
                case sf::Keyboard::F12:
                    game.leveleditor.resize();
                    game.switchState(GameState::LevelEditor);
                    break;
                default:
                    break;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    game.states[game.currentState]->eventHandler.handleClick(event.mouseButton.x, event.mouseButton.y);
                }
                
            }
        
        game.player.isShift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
        game.player.isCtrl = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
        }
        
        float dt = clock.restart().asSeconds();
        if (dt > 0.02){ dt = 0.02;}

        game.run(dt, leftoverTime);

    
        window.display();
    }
    return 0;
}