#pragma once
#include <optional>
#include "../gameFont.hpp"
#include "SFML/Graphics.hpp"
#include "gameState.hpp"
#include "../resourceManager.hpp"
#include "UIContainer.hpp"
#include "../balloon.hpp"
#include "../obstacle.hpp"

const float PHYSICS_TIME_STEP = 0.0166667;

void update(PhysicsObject& obj);

class PlayingGameState{
    public:
    std::optional<GameState> requestState;
    sf::RenderWindow& window;
    GameFont& fonts;
    ResourceManager resourcemanager;
    UIContainer playingScreen;
    bool alive = true;
    PlayingGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara);
    void show(float dt, double& leftoverTime, std::vector<Obstacle>& obstacles, Balloon& player );
    void resize(std::vector<Obstacle>& obstacles, Balloon& player);
};