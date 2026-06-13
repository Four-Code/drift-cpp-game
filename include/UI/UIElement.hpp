#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
class UIElement{
    public:
    virtual ~UIElement() = default;
    
    sf::Vector2f Position={0, 0};
    float rotatationAngle;
    virtual void draw(sf::RenderTarget& target);
    virtual sf::Vector2f getBoundingSize();
    sf::Vector2f getPosition();
    virtual void setPosition(sf::Vector2f newPosition)=0;
    void setParent(UIElement* parentP);
    UIElement* getParent();
    virtual void handleEvent(const sf::Event& event);
    private:
    UIElement* parent;
};