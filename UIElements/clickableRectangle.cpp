#include "clickableRectangle.hpp"

void ClickableRectangle:: click(){
    if (onClick){
        onClick();
    }
};

sf::Vector2f ClickableRectangle::getSize(){
    return sf::Vector2f(width, height);
}

ClickableRectangle::ClickableRectangle(float width, float height, sf::Color color, std::function<void()> onClick)
:width(width), height(height), color(color), onClick(onClick), 
shape(sf::Vector2f(width, height))
{
    
};

void ClickableRectangle::draw(sf::RenderTarget& window){
    shape.setPosition(position);
    window.draw(shape);
}