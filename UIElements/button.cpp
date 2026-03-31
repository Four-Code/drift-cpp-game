#include "button.hpp"
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"

GUIButton::GUIButton(sf::Color color, float width, float height, const std::string& textPara, sf::Font& fontPara, sf::Vector2f posPara, ResourceManager& resourcemanagerpara ,std::function<void()> action )
:shape(sf::Vector2f(width-height, height)), 
shapeShadow(sf::Vector2f(width-height, height)),
font(fontPara), 
shapeText(textPara, font), 
resourcemanager(resourcemanagerpara),
onClick(action),
btnColor(color),
width(width),
height(height),
shadowOffset(0.05*width),
shadowColor(84, 123, 131),
isHover(false),
hoverColor(btnColor.r*0.9, btnColor.g*0.9, btnColor.b*0.9)
{
    setPosition(posPara);
    
    shape.setFillColor(color);
    shapeShadow.setFillColor(shadowColor);

    rightCircle.setOrigin(height/2, height/2);
    rightCircle.setRadius(height/2);
    rightCircle.setFillColor(color);

    rightCircleShadow.setOrigin(height/2, height/2);
    rightCircleShadow.setRadius(height/2);
    rightCircleShadow.setFillColor(shadowColor);

    leftCircle.setOrigin(height/2, height/2);
    leftCircle.setRadius(height/2);
    leftCircle.setFillColor(color);

    leftCircleShadow.setOrigin(height/2, height/2);
    leftCircleShadow.setRadius(height/2);
    leftCircleShadow.setFillColor(shadowColor);

    shapeText.setFillColor(sf::Color::Black);
}

void GUIButton::setTextSize(float size){
    shapeText.setCharacterSize(size*width/100);
}

void GUIButton::draw(sf::RenderTarget& target){
    arrangeDrawableObjects();
    if (!isHover){
        target.draw(shapeShadow);
        target.draw(rightCircleShadow);
        target.draw(leftCircleShadow);
    }
    target.draw(shape);
    target.draw(rightCircle);
    target.draw(leftCircle);
    target.draw(shapeText);
}

sf::Vector2f GUIButton::getSize(){
    return sf::Vector2f(width, height);
}

void GUIButton::click(){
    if(onClick){
        onClick();
    }
}

void GUIButton::arrangeDrawableObjects(){
    sf::Vector2f pos = getPosition();
    shape.setPosition(sf::Vector2f(pos.x+height/2, pos.y));
    shapeShadow.setPosition(sf::Vector2f(pos.x+height/2+shadowOffset, pos.y+shadowOffset));
    rightCircle.setPosition(sf::Vector2f(pos.x+(width-height/2), pos.y+height/2));
    rightCircleShadow.setPosition(sf::Vector2f(pos.x+(width-height/2) +shadowOffset, pos.y+height/2+shadowOffset));
    leftCircle.setPosition(sf::Vector2f(pos.x+height/2, pos.y+height/2));
    leftCircleShadow.setPosition(sf::Vector2f(pos.x+height/2+shadowOffset,pos.y+ height/2 + shadowOffset));
    sf::FloatRect textBounds = shapeText.getLocalBounds();
    shapeText.setPosition(sf::Vector2f(pos.x+ (width-textBounds.width)/2+ 0.02*width - textBounds.left, (pos.y+(height-textBounds.height)/2) - textBounds.top ));
};

void GUIButton::hover(){
    if (!isHover){ 
        isHover = true;
        shape.setFillColor(hoverColor);
        rightCircle.setFillColor(hoverColor);
        leftCircle.setFillColor(hoverColor);
    }
}
void GUIButton::unhover(){
    if (isHover){
        isHover = false;
        shape.setFillColor(btnColor);
        rightCircle.setFillColor(btnColor);
        leftCircle.setFillColor(btnColor);
    }
}