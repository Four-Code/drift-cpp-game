#include "eventHandler.hpp"
#include "UIElements/button.hpp"

void EventHandler::addButton(GUIButton& btn){
    buttons.push_back(&btn);
}

void EventHandler::handleClick(int x, int y){
    for( GUIButton* button : buttons){
        sf::Vector2f buttonPos = button->getPosition();

        if (buttonPos.x < x && x < buttonPos.x +button->getSize().x ){
            if (buttonPos.y < y && y < buttonPos.y +button->getSize().y){
                button->click();
                button->unhover();
            }
        }
    }

    for ( ClickableRectangle* element: clickElements){
        sf::Vector2f pos = element->getPosition();
        if (pos.x < x && x < pos.x +element->getSize().x ){
            if (pos.y < y && y < pos.y +element->getSize().y){
                element->click();
            }
        }

    }
}

void EventHandler::addClickableRect(ClickableRectangle& element){
    clickElements.push_back(&element);
};

void EventHandler::handleHover(int x, int y){
    for( GUIButton* button : buttons){
        sf::FloatRect buttonPos(button->getPosition(), button->getSize());

        if (buttonPos.contains(sf::Vector2f(x, y))){
            button->hover();
        }
        else{
            button->unhover();
        }
    }
};