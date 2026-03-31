#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"
#include "UIElement.hpp"
 
class GUIButton: public UIElement{
    public:
    sf::RectangleShape shape;
    sf::Font& font;
    sf::Text shapeText;
    std::function<void()> onClick;
    ResourceManager resourcemanager;
    sf::Color btnColor;
    sf::Color hoverColor;
    sf::CircleShape rightCircle;
    sf::CircleShape leftCircle;
    float width; float height;

    sf::Color shadowColor;
    sf::RectangleShape shapeShadow;
    sf::CircleShape rightCircleShadow;
    sf::CircleShape leftCircleShadow;
    float shadowOffset;
    bool isHover;

    
    
    GUIButton(sf::Color color, float width, float height, const std::string& textPara, sf::Font& fontPara, sf::Vector2f posPara, ResourceManager& resourcemanagerpara, std::function<void()>action);
    
    void click();
    
    sf::Vector2f getSize() override;
    void arrangeDrawableObjects();
    void draw(sf::RenderTarget& target) override;
    void setTextSize(float size);
    void hover();
    void unhover();
};