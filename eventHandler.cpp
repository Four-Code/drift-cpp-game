#include "eventHandler.hpp"
#include "UIElements/button.hpp"

void EventHandler::addButton(GUIButton& btn){
    buttons.push_back(&btn);
}

void EventHandler::handleClick(int x, int y){
    for( GUIButton* button : buttons){
        sf::Vector2f buttonPos = button->getGlobalPosition();

        if (buttonPos.x < x && x < buttonPos.x +button->getSize().x ){
            if (buttonPos.y < y && y < buttonPos.y +button->getSize().y){
                button->click();
            }
        }
    }
}