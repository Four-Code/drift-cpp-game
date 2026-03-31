#include "pausedState.hpp"
#include <iostream>

PausedState::PausedState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerPara, GameState state)
:GameStateBase(windowPara, fontsPara, resourcemanagerPara, state),
pausedText("Paused", fonts.arial, sf::Color::Black),
bg(sf::Color(0, 0, 0, 50), window.getSize().x, window.getSize().y)
{
    bg.setPosition(sf::Vector2f(0, 0));
    cContainer.add(pausedText);
    mainScreen.add(cContainer);
    mainScreen.add(bg);
    resize();
};

void PausedState::show(){
    mainScreen.draw(window);
}

void PausedState::resize(){
    sf::Vector2u winSize = window.getSize();
    cContainer.width = winSize.x;
    cContainer.height = winSize.y;
    pausedText.marginTop = 0.4;
    bg.setSize(sf::Vector2f(winSize.x, winSize.y));
    cContainer.arrange();
}