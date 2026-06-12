#include "UI/Container.hpp"
#include "UI/UIElement.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

void Container::draw(sf::RenderTarget& target){
    for (auto& element : elements) {
        element->draw(target);
    }
}

void Container::setPosition(sf::Vector2f newPosition){
    UIElement::Position = newPosition;
}