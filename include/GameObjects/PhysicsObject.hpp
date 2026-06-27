#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
class PhysicsObject{
    public:
    sf::Vector2f Position;
    sf::Vector2f Velocity;
    sf::Vector2f Acceleration;
    void integrate(float dt);
    virtual void draw(sf::RenderTarget& target)=0;
};
sf::Vector2f convertToPixel(sf::Vector2f worldCoords, float screenHeight);
float convertLengthToPixel(float worldLength);