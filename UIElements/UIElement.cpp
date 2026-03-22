#include "UIElement.hpp"


void UIElement::setParent(UIElement& parentPara){
    parent = &parentPara;
}

sf::Vector2f UIElement::getPosition(){
    sf::Vector2f pos = this->position;

    // if (parent){
    //     pos += parent->getPosition();
    // }
    return pos;

}

void UIElement::setPosition(sf::Vector2f pos){
    this->position = pos;
}