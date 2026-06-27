#include "GameObjects/Obstacles/Needle.hpp"
#include "GameObjects/PhysicsObject.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Needle::Needle()
:shape({convertLengthToPixel(width), convertLengthToPixel(height)})
{}

void Needle::draw(sf::RenderTarget& target){
    shape.setSize({convertLengthToPixel(width), convertLengthToPixel(height)});
    shape.setPosition(convertToPixel(PhysicsObject::Position, target.getSize().y));
    target.draw(shape);
}