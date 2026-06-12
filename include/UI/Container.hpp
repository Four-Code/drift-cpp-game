#pragma once
#include "UI/UIElement.hpp"
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
#include "utility"
class Container:public UIElement{
    public:
    std::vector<std::unique_ptr<UIElement>> elements;

    // u need to move the ownership from unique pt to the vector, so we use std::move
    //declaring here, because templates need to be written like this
    template<typename T, typename... Args>
    T& addElement(Args&&... args){
        auto element = std::make_unique<T>(std::forward<Args>(args)...);
        T& ref = *element;
        element->setParent(this);
        elements.push_back((std::move(element)));
        return ref;
    }
    void setPosition(sf::Vector2f newPosition)override;
    void draw(sf::RenderTarget& target)override;
};