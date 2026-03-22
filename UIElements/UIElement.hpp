#pragma once
#include <SFML/Graphics.hpp>

class UIElement{
    public:
    sf::Vector2f position;
    float marginBottom = 0;
    float marginTop = 0;
    UIElement* parent = nullptr;
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);
    void setParent(UIElement& parentPara);
    virtual sf::Vector2f getSize()=0;
    virtual void draw(sf::RenderTarget& target)=0;
};