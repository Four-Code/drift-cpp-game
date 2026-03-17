#include "home.hpp"
#include "../gameFont.hpp"
#include <SFML/Graphics.hpp>
#include "UIContainer.hpp"
#include <iostream>
#include "../eventHandler.hpp"
#include "gameState.hpp"
#include "../resourceManager.hpp"
#include "centerContainer.hpp"
#include <memory>

//Home Screen
HomeGameState::HomeGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara)
:buttonFactor(0.8),
window(windowPara), 
fonts(fontsPara), 
versionNumberText("1.0.0", fontsPara.arial, sf::Color::Black), 
start(sf::Color(255, 0, 0), resourcemanager.buttonSprite.getLocalBounds().width*buttonFactor, resourcemanager.buttonSprite.getLocalBounds().height*buttonFactor, "Start", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
}),
level(sf::Color::Black, resourcemanager.buttonSprite.getLocalBounds().width*buttonFactor, resourcemanager.buttonSprite.getLocalBounds().height*buttonFactor, "Levels", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::Menu;
}),
resourcemanager(resourcemanagerpara)

{
    centercontainer.width = window.getSize().x;
    start.marginTop = window.getSize().y *0.6;

    level.marginTop = window.getSize().y *0.75;

    versionNumberText.setPosition(sf::Vector2f(100, 600));

    centercontainer.add(start);
    centercontainer.add(level);

    homeScreen.add(centercontainer);
    homeScreen.add(versionNumberText);
    eventHandler.addButton(start);
    eventHandler.addButton(level);
}

void HomeGameState::show(){
    this->window.clear();
    float factorW = window.getSize().x / resourcemanager.homeBg.getLocalBounds().width;
    float factorH = window.getSize().y / resourcemanager.homeBg.getLocalBounds().height;
    resourcemanager.homeBg.setScale(sf::Vector2f(factorW, factorH));
    this->window.draw(resourcemanager.homeBg);
    this->window.draw(homeScreen);
}
