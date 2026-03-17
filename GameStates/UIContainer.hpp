#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../UIElements/UIElement.hpp"

class UIContainer: public UIElement{
    public:
    std::vector<UIElement*> elements;
    float height;
    float width;

    void add(UIElement& element);

    private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2f getSize()override;
}; 