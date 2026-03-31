#include "gameState.hpp"
#include <iostream>

std::vector<Needle> Game::spawnObstacles(std::vector<spawnData>& level){
    std::vector<Needle> result;
    for (int i = 0; i < level.size(); i++){
        Needle obstacle(needleWidth, needleHeight, level[i].color, level[i].Pattern);
        obstacle.y = level[i].y;
        obstacle.vx = level[i].vx;
        obstacle.x =  (window.getSize().x-level[i].spawnTime * obstacle.vx);
        obstacle.Pattern = level[i].Pattern;
        result.push_back(obstacle);
    }
    return result;
    
}

Game::Game(sf::RenderWindow& window, GameFont& fonts, ResourceManager& resourcemanager)
:window(window), fonts(fonts), resourcemanager(resourcemanager),
home(window, fonts, resourcemanager, GameState::Home),
menu(window, fonts, resourcemanager, GameState::Menu),
playingState(window, fonts, resourcemanager, player, obstacles, GameState::Playing),
gameover(window, fonts, resourcemanager, GameState::GameOver),
pausedstate(window, fonts, resourcemanager, GameState::Paused),
leveleditor(window, fonts, resourcemanager, GameState::LevelEditor),
loadLevelStateObject(window, fonts, resourcemanager, GameState::LoadLevel),
currentState(GameState::Home),
states({&home, &menu, &loadLevelStateObject, &playingState, &pausedstate, &gameover, &leveleditor})
{
    levels.levels.resize(10);
    menu.requestLevelNo = 1;

}
void Game::run(float dt, double& leftoverTime){
    //handling transitions
    if (states[currentState]->requestState.has_value()){
        GameStateBase* & prevState = states[currentState];
        GameStateBase* & newState = states[prevState->requestState.value()];

        prevState->updateTransition(dt);

        if (!prevState->transitionstate.has_value()){
            prevState->startTransitionOut();
        }
        else{
            if (prevState->transitionstate.value() == TransitionState::over){
                if (!newState->transitionstate.has_value()){
                    switchState(prevState->requestState.value());
                    newState->requestState= newState->state;
                    newState->startTransitionIn();
                }
                newState->updateTransition(dt);
                if (newState->transitionstate.value() == TransitionState::over){
                    prevState->resetTransitionFlags();
                    newState->resetTransitionFlags();
                }
            }
        }
        
    }
    
        switch (currentState){
            case GameState::Home: {
                home.show();
                break;
            }

            case GameState::Menu:{
                menu.show();                
                break;
            }
            
            case GameState::LoadLevel: {
                window.create(sf::VideoMode::getDesktopMode(), "Drift", sf::Style::Fullscreen);
                window.setFramerateLimit(60);
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
                playingState.firstframe = true;
                playingState.resize();
                loadLevelStateObject.requestState = GameState::Playing;

                break;
            }
            
            case GameState::Playing: {
                playingState.play(dt, leftoverTime);
                if (!playingState.alive){playingState.requestState=GameState::GameOver; playingState.alive=true;}
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){playingState.requestState=GameState::Paused;}
            
                break;
            }

            case GameState::Paused:{
                leftoverTime = 0;
                playingState.play(0, leftoverTime);
                pausedstate.show();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){playingState.firstframe=true; pausedstate.requestState= GameState::Playing;}
                break;
            }

            case GameState::GameOver:{
                gameover.show();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ gameover.requestState=GameState::Home; break;}
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){ gameover.requestState = GameState::LoadLevel;}
                break;
            }
            case GameState::LevelEditor:{
                leveleditor.show(dt, leftoverTime);
                break;
            }
        }
}