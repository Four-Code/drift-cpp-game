#pragma once
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"
#include "UIContainer.hpp"
#include "centerContainer.hpp"
#include "../UIElements/text.hpp"
#include "gameStateBase.hpp"

class GameOverState:public GameStateBase{
    public:
    UIText gameOverText;
    CenterContainer cContainer;
    GameOverState(sf::RenderWindow& window, GameFont& fonts, ResourceManager& resourcemanager, GameState state);
    void resize() override;
};