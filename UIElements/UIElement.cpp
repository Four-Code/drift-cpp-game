#include "UIElement.hpp"


void UIElement::setParent(UIElement& parentPara){
    parent = &parentPara;
}

sf::Vector2f UIElement::getGlobalPosition(){
    sf::Vector2f pos = this->getPosition();

    if (parent){
        pos += parent->getGlobalPosition();
    }
    return pos;

}