#pragma once
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"
#include "UIContainer.hpp"
#include "centerContainer.hpp"
#include "../UIElements/text.hpp"
#include "../UIElements/colorRectangle.hpp"
#include "gameStateBase.hpp"

class PausedState: public GameStateBase{
    public:
    UIText pausedText;
    ColorRectangle bg;
    CenterContainer cContainer;
    PausedState(sf::RenderWindow& window, GameFont& fonts, ResourceManager& resourcemanager, GameState state);

    void resize()override;
    void show() override;
};