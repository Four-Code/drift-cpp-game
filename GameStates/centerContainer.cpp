#include "centerContainer.hpp"
#include <SFML/Graphics.hpp>
#include "../UIElements/UIElement.hpp"

void CenterContainer::add(UIElement& element){
    elements.push_back(&element);
    element.setParent(*this);
    arrange();
}

void CenterContainer::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    for (UIElement* element: elements){
        target.draw(*element, states);
    }
}

sf::Vector2f CenterContainer::getSize(){
    return sf::Vector2f(width, height);
}

void CenterContainer::arrange(){
    for (int i = 0; i < elements.size(); i++){
        (*elements[i]).setPosition(sf::Vector2f((width-(*elements[i]).getSize().x)/2, 0));

        sf::Vector2f initPos = (*elements[i]).getPosition();

        (*elements[i]).setPosition(sf::Vector2f(initPos.x, initPos.y + height* ((*elements[i]).marginTop)));
    
    }
    
}