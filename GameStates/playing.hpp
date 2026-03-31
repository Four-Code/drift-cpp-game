#pragma once
#include <optional>
#include "../gameFont.hpp"
#include "SFML/Graphics.hpp"
#include "../resourceManager.hpp"
#include "UIContainer.hpp"
#include "../balloon.hpp"
#include "../obstacle.hpp"
#include "../needle.hpp"
#include "../levelSys.hpp"
#include "gameStateBase.hpp"
#include "../UIElements/text.hpp"

const float PHYSICS_TIME_STEP = 0.0166667;

void update(PhysicsObject& obj);

class PlayingGameState: public GameStateBase{
    public:
    std::vector<Needle>& obstacles;
    UIText fps;
    Balloon& player;
    bool alive = true;
    bool firstframe;

    PlayingGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara, Balloon& playerP,  std::vector<Needle>& obstaclesP, GameState state);
    void play(float dt, double& leftoverTime);
    void resize()override;

    void show()override;
};