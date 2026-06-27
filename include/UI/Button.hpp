#pragma once

#include "UI/UIElement.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <functional>
#include <optional>
#include <string>

//position represents the top left corner, values are wrt to the parent not global screen coords.

class Button: public UIElement{
    public:
    float width;
    float height;
    std::string textvalue;
    sf::Font& font;
    void click();
    Button(std::string textP, sf::Font& fontP, float widthP, float heightP, std::function<void()> action);
    void draw(sf::RenderTarget& target)override;
    void setPosition(sf::Vector2f newPosition)override;
    void setBorderRadius(float newBorderRadius);
    void updatePositions();
    void handleEvent(const std::optional<sf::Event>& event)override;
    void hover();
    void unhover();
    private:
    float borderRadius = 10;
    std::function<void()>onclick;
    sf::Color btncolor = sf::Color::White;
    sf::ConvexShape middle;
    sf::CircleShape topright;
    sf::CircleShape bottomright;
    sf::CircleShape topleft;
    sf::CircleShape bottomleft;
    sf::Text label;
};