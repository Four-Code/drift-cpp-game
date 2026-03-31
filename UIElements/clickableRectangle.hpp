#pragma once 
#include "../UIElements/UIElement.hpp"
#include <SFML/Graphics.hpp>
#include <functional>

class ClickableRectangle:public UIElement{
    public:
    std::function<void()> onClick;
    float width;
    float height;
    sf::Color color;
    sf::Vector2f getSize()override;
    sf::RectangleShape shape;
    void click();
    void draw(sf::RenderTarget& window)override;
    ClickableRectangle(float width, float height, sf::Color color, std::function<void()> onClick);
};