#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "UIContainer.hpp"
#include "../UIElements/UIElement.hpp"

class CenterContainer: public UIElement{
    public:
    std::vector<UIElement*> elements;
    float height = 0;
    float width = 0;
    void add(UIElement& element);
    void arrange();
    private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2f getSize() override;
};