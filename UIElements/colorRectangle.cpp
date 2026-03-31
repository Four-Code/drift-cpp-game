#include "colorRectangle.hpp"
#include <iostream>

ColorRectangle::ColorRectangle(sf::Color color, float width, float height)
:color(color), height(height), width(width), shape(sf::Vector2f(width, height)), filltype(FillType::Color)
{
}
ColorRectangle::ColorRectangle(sf::Texture& texturep, float width, float height)
:texture(&texturep), filltype(FillType::Texture), shape({width, height})
{
    shape.setTexture(texture);

}
ColorRectangle::ColorRectangle(sf::VertexArray gradient, float width, float height)
:filltype(FillType::Gradient), shape({width, height})
{

}
sf::Vector2f ColorRectangle::getSize(){
    return sf::Vector2f(width, height);
}

void ColorRectangle:: setSize(sf::Vector2f size){
    width = size.x;
    height = size.y;
    shape.setSize(size);
}

void ColorRectangle::draw(sf::RenderTarget& target){
    shape.setPosition(position);
    switch (filltype)
    {
    case FillType::Color:
        shape.setFillColor(color);
        target.draw(shape);
        break;
    case FillType::Texture:
        shape.setTexture(texture);
        target.draw(shape);
        break;
    default:
        break;
    }

}