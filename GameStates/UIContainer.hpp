#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../UIElements/UIElement.hpp"

class UIContainer: public UIElement{
    public:
    std::vector<UIElement*> elements;
    float height;
    float width;

    float autoPosition = false;

    void add(UIElement& element);
    void draw(sf::RenderTarget& target) override;
    void arrange();
    sf::Vector2f getSize()override;
}; 