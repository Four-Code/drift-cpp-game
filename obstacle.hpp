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
    std::vector<PatternStep> Pattern;
    Obstacle(float width, float height, std::vector<PatternStep> Pattern);
    void executePattern();
    void update(float dt);
    virtual void show(sf::RenderWindow& window)=0;
};
