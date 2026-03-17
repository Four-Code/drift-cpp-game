#include "button.hpp"
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"

GUIButton::GUIButton(sf::Color color, float width, float height, const std::string& textPara, sf::Font& fontPara, sf::Vector2f posPara, ResourceManager& resourcemanagerpara ,std::function<void()> action )
:shape(sf::Vector2f(width, height)), 
font(fontPara), 
shapeText(textPara, font), 
pos(posPara),
resourcemanager(resourcemanagerpara),
onClick(action)
{
    shape.setTexture(&resourcemanager.buttonTexture);
    shapeText.setFillColor(sf::Color::Black);
    shapeText.setPosition(sf::Vector2f(pos.x+width/3, pos.y+height/4));
    
}

void GUIButton::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(shape, states);
    target.draw(shapeText, states);
}

sf::Vector2f GUIButton::getSize(){
    return sf::Vector2f(shape.getGlobalBounds().width, shape.getGlobalBounds().height);
}