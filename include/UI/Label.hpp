#pragma once

#include "UI/UIElement.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

//position represents TOP LEFT of the textbox

class Label: public UIElement{
    public:
    Label(std::string textP, sf::Font& fontP, float fontSizeP);
    void updateText(std::string textP);
    void updateFont(sf::Font& fontP);
    void upDateFontSize(float fontsizeP);
    void draw(sf::RenderTarget& target)override;
    sf::Vector2f getBoundingSize()override;
    void setPosition(sf::Vector2f newPosition)override;

    private:
    sf::Text sfmltextobject;
    std::string textValue;
    sf::Font& font;
    float fontSize;
};