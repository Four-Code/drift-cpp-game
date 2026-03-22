#include "centerContainer.hpp"
#include <SFML/Graphics.hpp>
#include "../UIElements/UIElement.hpp"

void CenterContainer::add(UIElement& element){
    element.setParent(*this);
    elements.push_back(&element);
    arrange();
}

void CenterContainer::draw(sf::RenderTarget& target){
    arrange();
    for (UIElement* element: elements){
        (*element).draw(target);
    }
}

sf::Vector2f CenterContainer::getSize(){
    return sf::Vector2f(width, height);
}

void CenterContainer::arrange(){
    for (int i = 0; i < elements.size(); i++){
        sf::Vector2f selfPos = getPosition();
        (*elements[i]).setPosition(sf::Vector2f(selfPos.x+ (width-(*elements[i]).getSize().x)/2, selfPos.y + height* ((*elements[i]).marginTop)));
    
    }
    
}