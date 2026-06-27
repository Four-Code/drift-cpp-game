#pragma once

#include "GameObjects/PhysicsObject.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Balloon:public PhysicsObject{
    public:
    float radius = 50;
    void draw(sf::RenderTarget& target)override;
    Balloon();
    private:
    sf::CircleShape shape;
};