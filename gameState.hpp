#pragma once
#include "GameStates/home.hpp"
#include "GameStates/levels.hpp"
#include "GameStates/playing.hpp"
#include "GameStates/leveleditor.hpp"
#include "GameStates/gameOver.hpp"
#include "GameStates/pausedState.hpp"
#include "GameStates/loadLevelState.hpp"
#include "GameStates/gameStateBase.hpp"
#include <SFML/Graphics.hpp>
#include "gameFont.hpp"
#include "resourceManager.hpp"
#include "levelSys.hpp"
#include "needle.hpp"

class Game{
    public:
    GameState currentState;
    sf::RenderWindow& window;
    GameFont& fonts;
    ResourceManager& resourcemanager;
    
    std::vector<Needle> obstacles;

    Balloon player;

    //home screen
    HomeGameState home;

    //levels
    Levels levels;

    //load level state object
    LoadLevelGameState loadLevelStateObject;

    //menu
    LevelGameState menu;

    //playing screen
    PlayingGameState playingState;

    //Game Over Screen
    GameOverState gameover;

    //Pause Screen
    PausedState pausedstate;

    //level editor
    LevelEditorGameState leveleditor;

    std::vector<GameStateBase*> states;

    const float needleHeight = 0.04f;
    const float needleWidth = 0.08f;
    const float playerRadius = 0.025f;
    bool fullScreen = false;


    Game(sf::RenderWindow& window, GameFont& fonts, ResourceManager& resourcemanager);

    void switchState(GameState state){
        // states[currentState]->startTransitionOut();
        // if (states[currentState]->isTransitionOver){
            currentState = state;
            states[currentState]->resize();
        // }
    }
    std::vector<Needle> spawnObstacles(std::vector<spawnData>& level);
    void run(float dt, double& leftoverTime);
};