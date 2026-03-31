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
HomeGameState::HomeGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara, GameState state)
:buttonFactor(0.8),
GameStateBase(windowPara, fontsPara, resourcemanagerpara, state),
gameNameLabel("Drift", fontsPara.dracula, sf::Color(24, 1, 82)), 
start(sf::Color(237, 229, 138), 240, 80, "Start", fonts.coolItalic, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
}),
level(sf::Color(237, 229, 138), 240, 80, "Levels", fonts.coolItalic, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::Menu;
}),
gameNameLabelScale(0.28),
homeBalloon(resourcemanager.homeBalloonTexture, resourcemanager.homeBalloonTexture.getSize().x, resourcemanager.homeBalloonTexture.getSize().y),
homeCloudLeft(resourcemanager.homeCloudTexture, resourcemanager.homeCloudTexture.getSize().x, resourcemanager.homeCloudTexture.getSize().y),
homeCloudRight(resourcemanager.homeCloudTexture, resourcemanager.homeCloudTexture.getSize().x, resourcemanager.homeCloudTexture.getSize().y),
needle1(resourcemanager.homeNeedleTexture, resourcemanager.homeNeedleTexture.getSize().x, resourcemanager.homeNeedleTexture.getSize().y),
needle2(resourcemanager.homeNeedleTexture, resourcemanager.homeNeedleTexture.getSize().x, resourcemanager.homeNeedleTexture.getSize().y),
needle3(resourcemanager.homeNeedleTexture, resourcemanager.homeNeedleTexture.getSize().x, resourcemanager.homeNeedleTexture.getSize().y),
needle4(resourcemanager.homeNeedleTexture, resourcemanager.homeNeedleTexture.getSize().x, resourcemanager.homeNeedleTexture.getSize().y),
transitionSpeed(1)
{
    centercontainer.width = window.getSize().x;
    centercontainer.height = window.getSize().y;
    start.marginTop = 0.55;
    level.marginTop = 0.7;
    start.setTextSize(15);
    level.setTextSize(15);

    gameNameLabel.marginTop = 0.07;
    gameNameLabel.setSize(gameNameLabelScale*window.getSize().y);

    centercontainer.add(start);
    centercontainer.add(level);
    centercontainer.add(gameNameLabel);

    mainScreen.add(homeBalloon);
    mainScreen.add(homeCloudLeft);
    mainScreen.add(needle1);
    // mainScreen.add(needle2);
    homeCloudRight.shape.setTextureRect(sf::IntRect({resourcemanager.homeCloudTexture.getSize().x,0}, {-static_cast<int>(resourcemanager.homeCloudTexture.getSize().x), resourcemanager.homeCloudTexture.getSize().y}));
    mainScreen.add(homeCloudRight);

    needle3.shape.setTextureRect(sf::IntRect({resourcemanager.homeNeedleTexture.getSize().x,0}, {-static_cast<int>(resourcemanager.homeNeedleTexture.getSize().x), resourcemanager.homeNeedleTexture.getSize().y}));

    mainScreen.add(needle3);

    // needle4.shape.setTextureRect(sf::IntRect({resourcemanager.homeNeedleTexture.getSize().x,0}, {-static_cast<int>(resourcemanager.homeNeedleTexture.getSize().x), resourcemanager.homeNeedleTexture.getSize().y}));

    // mainScreen.add(needle4);

    mainScreen.add(centercontainer);
    eventHandler.addButton(start);
    eventHandler.addButton(level);

}

void HomeGameState::show(){
    window.clear();
    window.draw(resourcemanager.homeBg);
    mainScreen.draw(window);
}

void HomeGameState::resize(){
    sf::Vector2u winSize = window.getSize();
    float factorW = winSize.x / resourcemanager.homeBg.getLocalBounds().width;
    float factorH = winSize.y / resourcemanager.homeBg.getLocalBounds().height;
    resourcemanager.homeBg.setScale(sf::Vector2f(factorW, factorH));

    gameNameLabel.setSize(gameNameLabelScale*winSize.y);

    centercontainer.width = winSize.x;
    centercontainer.height = winSize.y;
    centercontainer.arrange();

    homeBalloon.setPosition({gameNameLabel.getPosition().x + gameNameLabel.getSize().x-70, gameNameLabel.getPosition().y-50});

    homeCloudLeft.setPosition({gameNameLabel.getPosition().x -240, gameNameLabel.getPosition().y+150});

    homeCloudRight.setPosition({gameNameLabel.getPosition().x + gameNameLabel.getSize().x-240, gameNameLabel.getPosition().y+150});

    needle1.setPosition({0.7f*winSize.x, 0.7f*winSize.y});
    // needle2.setPosition({0.6f*winSize.x, 0.6f*winSize.y});
    needle3.setPosition({0.03f*winSize.x, 0.7f*winSize.y});
    // needle4.setPosition({0.01f*winSize.x, 0.7f*winSize.y});

}

void HomeGameState::updateTransition(float dt){
    if(isTransitionOut){
        sf::Vector2u winsize = window.getSize();
        gameNameLabel.marginTop += -1.5*dt;
        start.marginTop += 2*dt*transitionSpeed;
        level.marginTop += 2*dt*transitionSpeed;
        homeCloudRight.setPosition({homeCloudRight.getPosition().x + 1.5*winsize.x*dt*transitionSpeed,homeCloudRight.getPosition().y});

        homeCloudLeft.setPosition({homeCloudLeft.getPosition().x - 1.5*winsize.x*dt*transitionSpeed,homeCloudLeft.getPosition().y});

        homeBalloon.setPosition(homeBalloon.getPosition()+sf::Vector2f{2*winsize.x*dt*transitionSpeed, -2*static_cast<int>(winsize.y)*dt*transitionSpeed});

        needle1.setPosition(needle1.getPosition()+sf::Vector2f{1.5*static_cast<int>(winsize.x)*dt*transitionSpeed, 1.5*static_cast<int>(winsize.y)*dt*transitionSpeed});        
        
        needle3.setPosition(needle3.getPosition()+sf::Vector2f{-1.5*static_cast<int>(winsize.x)*dt*transitionSpeed, 1.5*static_cast<int>(winsize.y)*dt*transitionSpeed});

        if (gameNameLabel.getPosition().y < -600){
            isTransitionOut=false;
            transitionstate = TransitionState::over;
        }
    }
    if (isTransitionIn){
        std::cout<<"Home transiton in";
        isTransitionIn = false;
        transitionstate = TransitionState::over;
    }
}