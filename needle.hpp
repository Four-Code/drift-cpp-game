#pragma once
#include "obstacle.hpp"

class Needle:public Obstacle{
    public:
    Needle(float width, float height, sf::Color color, std::vector<PatternStep> Pattern);
    sf::RectangleShape shape;
    void show(sf::RenderWindow& window) override;
};