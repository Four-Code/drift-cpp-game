#pragma once
#include <SFML/Graphics.hpp>
#include "physicsObject.hpp"
#include <vector>

enum class ActionType{SetVx, SetVy, Destory};
struct PatternStep{
    ActionType actionType;
    float triggerTime;
    float value;
};

class Obstacle:public PhysicsObject{
    public:
    sf::Color color;
    float width;
    float height;
    sf::RectangleShape shape;
    std::vector<PatternStep> Pattern;
    Obstacle(float width, float height, sf::Color color, std::vector<PatternStep> Pattern);
    void executePattern();
    void update(float dt);
};
