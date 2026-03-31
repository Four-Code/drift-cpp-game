#pragma once
#include "gameStateBase.hpp"
#include "../gameFont.hpp"
#include "../resourceManager.hpp"
#include <SFML/Graphics.hpp>

class LoadLevelGameState:public GameStateBase{
    public:
    LoadLevelGameState(sf::RenderWindow& windowp, GameFont& fontsp, ResourceManager& resourcemanagerp, GameState state);
};