#include <SFML/Graphics.hpp>
#include "text.hpp"

UIText::UIText(const std::string& str, sf::Font& font, sf::Color fontColor)
: shapeText(str, font)
{
    shapeText.setFillColor(fontColor);
}

sf::Vector2f UIText::getSize(){
    return sf::Vector2f(shapeText.getGlobalBounds().width, shapeText.getGlobalBounds().height);
}

void UIText::draw(sf::RenderTarget& target){
    shapeText.setPosition(position);
    target.draw(shapeText);
}

void UIText::setText(const std::string& str){
    shapeText.setString(str);
}

void UIText::setSize(int size){
    shapeText.setCharacterSize(size);
}