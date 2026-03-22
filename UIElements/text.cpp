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
    target.draw(shapeText);
}

void UIText::setText(const std::string& str){
    shapeText.setString(str);
}