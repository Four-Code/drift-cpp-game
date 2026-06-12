#pragma once

#include <SFML/System/Vector2.hpp>
class PhysicsObject{
    public:
    sf::Vector2f Position;
    sf::Vector2f Velocity;
    sf::Vector2f Acceleration;
    void integrate(float dt);
};
sf::Vector2f convertToPixel(sf::Vector2f worldCoords, float screenHeight);
float convertLengthToPixel(float worldLength);