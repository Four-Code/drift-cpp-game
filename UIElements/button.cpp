#include "button.hpp"
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"

GUIButton::GUIButton(sf::Color color, float width, float height, const std::string& textPara, sf::Font& fontPara, sf::Vector2f posPara, ResourceManager& resourcemanagerpara ,std::function<void()> action )
:shape(sf::Vector2f(width-height, height)), 
shapeShadow(sf::Vector2f(width-height, height)),
font(fontPara), 
shapeText(textPara, font), 
pos(posPara),
resourcemanager(resourcemanagerpara),
onClick(action),
btnColor(color),
width(width),
height(height),
shadowOffset(0.05*width),
shadowColor(84, 123, 131)
{
    // shape.setTexture(&resourcemanager.buttonTexture);
    sf::Vector2f btnshapeData = getPosition();
    shape.setPosition(sf::Vector2f(btnshapeData.x+height/2, btnshapeData.y));
    shape.setFillColor(sf::Color(237, 229, 138));

    shapeShadow.setPosition(sf::Vector2f(btnshapeData.x+height/2+shadowOffset, btnshapeData.y+shadowOffset));
    shapeShadow.setFillColor(shadowColor);

    rightCircle.setOrigin(height/2, height/2);
    rightCircle.setPosition(sf::Vector2f(btnshapeData.x+(width-height/2), btnshapeData.y+height/2));
    rightCircle.setRadius(height/2);
    rightCircle.setFillColor(sf::Color(237, 229, 138));

    rightCircleShadow.setOrigin(height/2, height/2);
    rightCircleShadow.setPosition(sf::Vector2f(btnshapeData.x+(width-height/2) +shadowOffset, btnshapeData.y+height/2+shadowOffset));
    rightCircleShadow.setRadius(height/2);
    rightCircleShadow.setFillColor(shadowColor);

    leftCircle.setOrigin(height/2, height/2);
    leftCircle.setPosition(sf::Vector2f(btnshapeData.x+height/2, btnshapeData.y+height/2));
    leftCircle.setRadius(height/2);
    leftCircle.setFillColor(sf::Color(237, 229, 138));

    leftCircleShadow.setOrigin(height/2, height/2);
    leftCircleShadow.setPosition(sf::Vector2f(btnshapeData.x+height/2+shadowOffset, btnshapeData.y+height/2 + shadowOffset));
    leftCircleShadow.setRadius(height/2);
    leftCircleShadow.setFillColor(shadowColor);

    shapeText.setFillColor(sf::Color::Black);
    sf::FloatRect textBounds = shapeText.getGlobalBounds();
    shapeText.setPosition(sf::Vector2f(btnshapeData.x+(width-textBounds.width)/2 - textBounds.left+ 0.02*width, btnshapeData.y+(height-textBounds.height)/2 - textBounds.top));
    
}

void GUIButton::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(shapeShadow, states);
    target.draw(rightCircleShadow, states);
    target.draw(leftCircleShadow, states);
    target.draw(shape, states);
    target.draw(rightCircle, states);
    target.draw(leftCircle, states);
    target.draw(shapeText, states);
}

sf::Vector2f GUIButton::getSize(){
    return sf::Vector2f(width, height);
}