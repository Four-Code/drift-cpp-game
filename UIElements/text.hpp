#pragma once
#include <SFML/Graphics.hpp>
#include "UIElement.hpp"

class UIText: public UIElement{
    public:
    sf::Text shapeText;
    UIText(const std::string& str, sf::Font& font, sf::Color fontColor);
    sf::Vector2f getSize() override;

    void setText(const std::string& str);
    void draw(sf::RenderTarget& target) override;
};