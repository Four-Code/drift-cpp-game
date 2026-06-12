#include "UI/UIElement.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

void UIElement::draw(sf::RenderTarget& target){}

sf::Vector2f UIElement::getBoundingSize(){return {0, 0};}

sf::Vector2f UIElement::getPosition(){ return UIElement::Position;}

void UIElement::setParent(UIElement* parentP){
    UIElement::parent = parentP;
}

UIElement* UIElement::getParent(){
    return parent;
}