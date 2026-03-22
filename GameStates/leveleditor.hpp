#pragma once
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"
#include "UIContainer.hpp"
#include "../eventHandler.hpp"
#include "../UIElements/button.hpp"
#include "../obstacle.hpp"
#include <vector>
#include "centerContainer.hpp"

class LevelEditorGameState{
    public:
    sf::RenderWindow& window;
    GameFont& fonts;
    ResourceManager& resourcemanager;
    UIContainer homeScreen;
    EventHandler eventHandler;
    UIContainer levelEditorScreen;
    GUIButton addObstacle;
    std::vector <Obstacle> obstacles;
    GUIButton play;
    GUIButton pause;
    GUIButton revind;
    CenterContainer cContainer;
    UIContainer controls;
    double editorTime;
    float isPlaying = true;

    LevelEditorGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara);
    void show(float dt, double& leftovertime);
    void resize();
};