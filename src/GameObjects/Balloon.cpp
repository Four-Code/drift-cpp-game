
#include "GameObjects/Balloon.hpp"
#include "GameObjects/PhysicsObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void Balloon::draw(sf::RenderTarget& target){
    shape.setPosition(convertToPixel(PhysicsObject::Position, target.getSize().y));
    shape.setRadius(radius);
    target.draw(shape);
}
Balloon::Balloon()
:shape(radius)
{
    shape.setOrigin(radius, radius);
}