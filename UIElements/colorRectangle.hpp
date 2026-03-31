#pragma once
#include "UIElement.hpp"
#include <SFML/Graphics.hpp>

enum FillType{Color, Texture, Gradient};

class ColorRectangle : public UIElement{
    public:
    sf::RectangleShape shape;
    sf::Color color;
    sf::Texture* texture = nullptr;
    sf::VertexArray gradient;
    FillType filltype;
    float width;
    float height;
    ColorRectangle(sf::Color color, float width, float height);
    ColorRectangle(sf::Texture& texture, float width, float height);
    ColorRectangle(sf::VertexArray gradient, float width, float height);
    sf::Vector2f getSize()override;
    void setSize(sf::Vector2f size);
    void draw(sf::RenderTarget& target)override;
};