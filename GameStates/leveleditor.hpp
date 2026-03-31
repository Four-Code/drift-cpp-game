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
#include "../UIElements/text.hpp"
#include "../UIElements/clickableRectangle.hpp"
#include "gameStateBase.hpp"

class EditableObstacle:public Obstacle{
    public:
    EditableObstacle(float width, float height, sf::Color color, std::function<void()> onClick);
    ClickableRectangle shape;
    void show(sf::RenderWindow& window)override;
};

class LevelEditorGameState: public GameStateBase{
    public:
    GUIButton addObstacle;
    std::vector <EditableObstacle> obstacles;
    GUIButton play;
    GUIButton pause;
    GUIButton revind;
    CenterContainer cContainer;
    UIContainer controls;
    UIText editorTimeDisplay;
    int direction = 1;
    double editorTime;
    float isPlaying = false;

    LevelEditorGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara, GameState state);
    void show(float dt, double& leftovertime);
    void resize();
};