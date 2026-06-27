#pragma once

#include "GameObjects/Obstacles/Obstacle.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
class Needle:public Obstacle{
    public:
    float height = 3;
    float width = 10;
    void draw(sf::RenderTarget& target);
    Needle();
    private:
    sf::RectangleShape shape;
};