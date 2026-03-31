#include "levels.hpp"
#include <SFML/Graphics.hpp>
#include "gameState.hpp"
#include <optional>
#include <iostream>

//menu
LevelGameState:: LevelGameState(sf::RenderWindow& windowPara, GameFont& gamefontpara, ResourceManager& resourcemanagerpara, GameState state)
:buttonFactor(0.8),
GameStateBase(windowPara, gamefontpara, resourcemanagerpara, state),
btnWidth(240),
btnHeight(80),
level1(sf::Color(237, 229, 138), btnWidth, btnHeight, "Level 1", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 1;
}),
level2(sf::Color(237, 229, 138), btnWidth, btnHeight, "Level 2", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 1;
}),
level3(sf::Color(237, 229, 138), btnWidth, btnHeight, "Level 3", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 3;
}),
level4(sf::Color(237, 229, 138), btnWidth, btnHeight, "Level 4", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 4;
}),
level5(sf::Color(237, 229, 138), btnWidth, btnHeight, "Level 5", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 5;
}),
level6(sf::Color(237, 229, 138), btnWidth, btnHeight, "Level 6", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 6;
}),
levels("Levels", fonts.dracula, sf::Color::Black),
transitionSpeed(2)
{
    level1.marginTop = 0.4;
    level2.marginTop = 0.55;
    level3.marginTop = 0.7;

    centercontainer1.add(level1);
    centercontainer1.add(level2);
    centercontainer1.add(level3);

    mainScreen.add(centercontainer1);
    
    level4.marginTop = 0.4;
    level5.marginTop = 0.55;
    level6.marginTop = 0.7;

    levels.marginTop = -0.1;

    centercontainer2.add(level4);
    centercontainer2.add(level5);
    centercontainer2.add(level6);

    levelcentercontainer.add(levels);
    levelcentercontainer.setPosition({0, 0});

    mainScreen.add(centercontainer2);
    mainScreen.add(levelcentercontainer);

    eventHandler.addButton(level1);
    eventHandler.addButton(level2);
    eventHandler.addButton(level3);
    eventHandler.addButton(level4);
    eventHandler.addButton(level5);
    eventHandler.addButton(level6);
    resize();
}

void LevelGameState::show(){
    window.clear();
    window.draw(resourcemanager.homeBg);
    mainScreen.draw(window);
}

void LevelGameState::resize(){
    sf::Vector2u winSize = window.getSize();
    float factorW = winSize.x / resourcemanager.homeBg.getLocalBounds().width;
    float factorH = winSize.y / resourcemanager.homeBg.getLocalBounds().height;
    resourcemanager.homeBg.setScale(sf::Vector2f(factorW, factorH));
    levels.setSize(0.15*winSize.y);

    centercontainer1.width = 0.6 * winSize.x;
    centercontainer1.setPosition(sf::Vector2f(-centercontainer1.width, 0));
    centercontainer2.width = 0.6 *winSize.x;
    centercontainer2.setPosition(sf::Vector2f(winSize.x, 0));
    centercontainer1.height = winSize.y;
    centercontainer2.height = winSize.y;
    levelcentercontainer.width = winSize.x;
    levelcentercontainer.height = winSize.y;
    centercontainer1.arrange();
    centercontainer2.arrange();
    levelcentercontainer.arrange();
}

void LevelGameState::updateTransition(float dt){
    if(isTransitionIn){
        sf::Vector2u winsize = window.getSize();
        centercontainer1.setPosition(centercontainer1.getPosition()+sf::Vector2f{transitionSpeed*winsize.x*dt,0});
        centercontainer2.setPosition(centercontainer2.getPosition()-sf::Vector2f{transitionSpeed*winsize.x*dt,0});
        levels.marginTop += transitionSpeed*0.4*dt;
        if (centercontainer1.getPosition().x>=0){
            isTransitionIn=false;
            transitionstate = TransitionState::over;
        }
    }
    if (isTransitionOut){
        isTransitionOut = false;
        transitionstate = TransitionState::over;
    }
}