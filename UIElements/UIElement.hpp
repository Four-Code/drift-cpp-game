#pragma once
#include <SFML/Graphics.hpp>

class UIElement: public sf::Drawable, public sf::Transformable{
    public:
    float marginBottom = 0;
    float marginTop = 0;
    UIElement* parent = nullptr;
    sf::Vector2f getGlobalPosition();
    void setParent(UIElement& parentPara);
    virtual sf::Vector2f getSize()=0;
};