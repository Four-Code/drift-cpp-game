#include "UI/Button.hpp"
#include "UI/UIElement.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>

Button::Button(std::string textP, sf::Font& fontP, float widthP, float heightP, std::function<void()> action)
:textvalue(textP),font(fontP), width(widthP), height(heightP), onclick(action), label(fontP, textP)
{
    topleft.setOrigin({borderRadius, borderRadius});
    topright.setOrigin({borderRadius, borderRadius});
    bottomleft.setOrigin({borderRadius, borderRadius});
    bottomright.setOrigin({borderRadius, borderRadius});
    middle.setPointCount(8);
    label.setFillColor(sf::Color::Black);
    Button::updatePositions();    
}
void Button::click(){
    if(onclick){
        onclick();
    }
}
void Button::draw(sf::RenderTarget& target){
    target.draw(topleft);
    target.draw(bottomleft);
    target.draw(topright);
    target.draw(bottomright);
    target.draw(middle);
    target.draw(label);
}
void Button::setPosition(sf::Vector2f newPosition){
    UIElement::Position = newPosition;
    Button::updatePositions();
}
void Button::setBorderRadius(float newBorderRadius){
    borderRadius = newBorderRadius;
    Button::updatePositions();
}
void Button::updatePositions(){
    topleft.setRadius(borderRadius);
    topright.setRadius(borderRadius);
    bottomleft.setRadius(borderRadius);
    bottomright.setRadius(borderRadius);

    middle.setPoint(0, {borderRadius, 0});
    middle.setPoint(1, {width - borderRadius, 0});
    middle.setPoint(2, {width, borderRadius});
    middle.setPoint(3, {width, height-borderRadius});
    middle.setPoint(4, {width-borderRadius, height});
    middle.setPoint(5, {borderRadius, height});
    middle.setPoint(6, {0, height-borderRadius});
    middle.setPoint(7, {0, borderRadius});


    topleft.setPosition(UIElement::getPosition() + sf::Vector2f{ borderRadius,  borderRadius});
    topright.setPosition(UIElement::getPosition() + sf::Vector2f{ width-borderRadius,  borderRadius});
    bottomleft.setPosition(UIElement::getPosition() + sf::Vector2f{ borderRadius,  height-borderRadius});
    bottomright.setPosition(UIElement::getPosition() + sf::Vector2f{ width-borderRadius,  height-borderRadius});
    middle.setPosition(UIElement::getPosition() + sf::Vector2f{ 0,  0});

    sf::FloatRect lableSize = label.getLocalBounds();
    label.setPosition(UIElement::getPosition()+ sf::Vector2f{(width-lableSize.size.x)/2, (height-lableSize.size.y)/2});
}
void Button::handleEvent(const std::optional<sf::Event>& event){
    sf::FloatRect buttonBounds(UIElement::getPosition(), {width, height});
    if(const auto* mousemoveevent = event->getIf<sf::Event::MouseMoved>()){
        if(buttonBounds.contains({static_cast<float>(mousemoveevent->position.x), static_cast<float>(mousemoveevent->position.y)})){
            Button::hover();
        }
        else{
            Button::unhover();
        }
    }
    if (const auto* mousebuttonpressedevent = event->getIf<sf::Event::MouseButtonPressed>()){
        if(buttonBounds.contains({static_cast<float>(mousebuttonpressedevent->position.x), static_cast<float>(mousebuttonpressedevent->position.y)})){
            Button::click();
        }
    }
}
void Button::hover(){
    float shadeConstant = 0.7;
    topleft.setFillColor({static_cast<uint8_t>((btncolor.r*shadeConstant)), (static_cast<uint8_t>(btncolor.g*shadeConstant)), static_cast<uint8_t>((btncolor.b*shadeConstant))});
    topright.setFillColor({static_cast<uint8_t>(btncolor.r*shadeConstant), static_cast<uint8_t>(btncolor.g*shadeConstant), static_cast<uint8_t>(btncolor.b*shadeConstant)});
    bottomleft.setFillColor({static_cast<uint8_t>(btncolor.r*shadeConstant), static_cast<uint8_t>(btncolor.g*shadeConstant), static_cast<uint8_t>(btncolor.b*shadeConstant)});
    bottomright.setFillColor({static_cast<uint8_t>(btncolor.r*shadeConstant), static_cast<uint8_t>(btncolor.g*shadeConstant), static_cast<uint8_t>(btncolor.b*shadeConstant)});
    middle.setFillColor({static_cast<uint8_t>(btncolor.r*shadeConstant), static_cast<uint8_t>(btncolor.g*shadeConstant), static_cast<uint8_t>(btncolor.b*shadeConstant)});
}
void Button::unhover(){
    topleft.setFillColor(btncolor);
    topright.setFillColor(btncolor);
    bottomleft.setFillColor(btncolor);
    bottomright.setFillColor(btncolor);
    middle.setFillColor(btncolor);
}