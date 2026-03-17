#include "UIContainer.hpp"
#include "../UIElements/UIElement.hpp"

void UIContainer::add(UIElement& element){
        elements.push_back(&element);
}

void UIContainer::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    states.transform *= getTransform();
    for (const auto& element: elements){
        target.draw(*element, states);
    }
};

sf::Vector2f UIContainer::getSize(){
    return sf::Vector2f(width, height);
}