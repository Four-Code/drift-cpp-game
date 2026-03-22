#include "UIContainer.hpp"
#include "../UIElements/UIElement.hpp"

void UIContainer::add(UIElement& element){
        elements.push_back(&element);
}

void UIContainer::draw(sf::RenderTarget& target){
    arrange();
    for (const auto& element: elements){
        (*element).draw(target);
    }
};

sf::Vector2f UIContainer::getSize(){
    return sf::Vector2f(width, height);
}

void UIContainer::arrange(){
    if (autoPosition){
        for (int i = 0; i < elements.size(); i++){
            sf::Vector2f selfPos = getPosition();
            (*elements[i]).setPosition(sf::Vector2f(selfPos.x + i *100, selfPos.y));
            
        }
    }
    
}