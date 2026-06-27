#include "UI/Label.hpp"
#include "UI/UIElement.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

Label::Label(std::string textP, sf::Font& fontP, float fontSizeP)
:textValue(textP), font(fontP), fontSize(fontSizeP), sfmltextobject(fontP, textP)
{}

void Label::updateFont(sf::Font& fontp){
    Label::font = fontp;
    sfmltextobject.setFont(Label::font);
}
void Label::upDateFontSize(float fontSizep){
    Label::fontSize = fontSizep;
    sfmltextobject.setCharacterSize(Label::fontSize);
}
void Label::updateText(std::string textP){
    Label::textValue = textP;
    sfmltextobject.setString(Label::textValue);
}
void Label::draw(sf::RenderTarget& target){
    target.draw(sfmltextobject);

}
sf::Vector2f Label::getBoundingSize(){
    return {0, 0};
}
void Label::setPosition(sf::Vector2f newPosition){
    UIElement::Position = newPosition;
    // as stated in the UI.hpp, Position represents the position wrt to the parent position
    sfmltextobject.setPosition(UIElement::Position+UIElement::getParent()->getPosition());
}