#pragma once
#include "physicsObject.hpp"
#include <SFML/Graphics.hpp>

// Player Class
class Balloon : public PhysicsObject{
public:
    sf::Color color;
    float radius;
    sf::CircleShape shape;
    bool isJump = false;
    bool isShift = false;
    bool isCtrl = false;

    Balloon(float radius = 100.00f, sf::Color color=sf::Color::Red);

    void setRadius(float radius);

    void setColor(sf::Color color);

    void update(float dt);
};
