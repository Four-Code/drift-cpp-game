#pragma once
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "UIContainer.hpp"
#include "../UIElements/button.hpp"
#include "../eventHandler.hpp"
#include "../resourceManager.hpp"
#include "../UIElements/text.hpp"
#include "centerContainer.hpp"
#include <vector>
#include "../levelSys.hpp"
#include "gameStateBase.hpp"
#include "../UIElements/colorRectangle.hpp"

class HomeGameState:public GameStateBase{
    public:
    float buttonFactor;
    double gameNameLabelScale;
    UIText gameNameLabel;
    GUIButton start;
    GUIButton level;
    CenterContainer centercontainer;
    ColorRectangle homeBalloon;
    ColorRectangle homeCloudLeft;
    ColorRectangle homeCloudRight;
    ColorRectangle needle1;
    ColorRectangle needle2;
    ColorRectangle needle3;
    ColorRectangle needle4;
    float transitionSpeed;

    HomeGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara, GameState state);
    void resize() override;
    void show() override;
    void updateTransition(float dt)override;
};