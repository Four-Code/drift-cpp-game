#include "needle.hpp"

Needle::Needle(float width, float height, sf::Color color, std::vector<PatternStep> Pattern)
:Obstacle(width, height, Pattern)
{
    shape.setFillColor(color);
}
void Needle::show(sf::RenderWindow& window){
    window.draw(shape);
}