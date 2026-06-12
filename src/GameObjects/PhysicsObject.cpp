#include "GameObjects/PhysicsObject.hpp"
#include <SFML/System/Vector2.hpp>

void PhysicsObject::integrate(float dt){
    Position += Velocity*dt;
    Velocity += Acceleration*dt;
}

sf::Vector2f convertToPixel(sf::Vector2f worldCoords, float screenHeight){
    float scale = 10;
    return {worldCoords.x*scale, screenHeight-(worldCoords.y*scale)};
}

float convertLengthToPixel(float worldLength){
    float scale = 10;
    return worldLength*scale;
}