#pragma once
#include "GameStates/GameStateBase.hpp"
#include "UI/GameFonts.hpp"

class HomeState:public GameStateBase{
    public:
    void init(GameFont& gameFonts)override;
    void show(sf::RenderTarget& target, float dt)override;
};