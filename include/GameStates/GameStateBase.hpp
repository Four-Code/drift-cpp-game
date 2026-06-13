#pragma once

#include "UI/Container.hpp"
#include "UI/GameFonts.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <optional>

enum GameState{Home, Playing};

class GameStateBase{
    public:
    Container parentContainer;
    GameState ID;
    std::optional<GameState> requestChange;
    virtual void init(GameFont& gameFonts)=0;
    virtual void show(sf::RenderTarget& target, float dt)=0;
};