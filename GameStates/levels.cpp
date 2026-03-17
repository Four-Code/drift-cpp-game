#include "levels.hpp"
#include <SFML/Graphics.hpp>
#include "gameState.hpp"
#include <optional>
#include <iostream>

//menu
LevelGameState:: LevelGameState(sf::RenderWindow& windowPara, GameFont& gamefontpara, ResourceManager& resourcemanagerpara)
:buttonFactor(0.8),
window(windowPara),
fonts(gamefontpara),
btnWidth(resourcemanager.buttonSprite.getLocalBounds().width*buttonFactor),
btnHeight(resourcemanager.buttonSprite.getLocalBounds().height*buttonFactor),
level1(sf::Color(0, 0, 0), btnWidth, btnHeight, "Level 1", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 1;
}),
level2(sf::Color(0, 0, 0), btnWidth, btnHeight, "Level 2", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 1;
}),
level3(sf::Color(0, 0, 0), btnWidth, btnHeight, "Level 3", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 3;
}),
level4(sf::Color(0, 0, 0), btnWidth, btnHeight, "Level 4", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 4;
}),
level5(sf::Color(0, 0, 0), btnWidth, btnHeight, "Level 5", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 5;
}),
level6(sf::Color(0, 0, 0), btnWidth, btnHeight, "Level 6", fonts.arial, sf::Vector2f(0, 0), resourcemanager,[&]{
    requestState = GameState::LoadLevel;
    requestLevelNo = 6;
}),
levels("Levels", fonts.arial, sf::Color::Black),
resourcemanager(resourcemanagerpara)
{
    sf::Vector2u winSize = window.getSize();
    centercontainer1.width = 0.6 * winSize.x;
    centercontainer1.setPosition(sf::Vector2f(0, 0));
    centercontainer2.width = 0.6 *winSize.x;
    centercontainer2.setPosition(sf::Vector2f(0.4*winSize.x, 0));

    level1.marginTop = 0.4 * winSize.y;
    level2.marginTop = 0.55 * winSize.y;
    level3.marginTop = 0.7 * winSize.y;

    centercontainer1.add(level1);
    centercontainer1.add(level2);
    centercontainer1.add(level3);

    LevelScreen.add(centercontainer1);
    
    level4.marginTop = 0.4 * winSize.y;
    level5.marginTop = 0.55 * winSize.y;
    level6.marginTop = 0.7 * winSize.y;

    centercontainer2.add(level4);
    centercontainer2.add(level5);
    centercontainer2.add(level6);

    LevelScreen.add(centercontainer2);

    eventHandler.addButton(level1);
    eventHandler.addButton(level2);
    eventHandler.addButton(level3);
    eventHandler.addButton(level4);
    eventHandler.addButton(level5);
    eventHandler.addButton(level6);

}

void LevelGameState::show(){
    window.clear();
    float factorW = window.getSize().x / resourcemanager.homeBg.getLocalBounds().width;
    float factorH = window.getSize().y / resourcemanager.homeBg.getLocalBounds().height;

    // resourcemanager.homeBg.setScale(sf::Vector2f(factor, factor));
    window.draw(resourcemanager.homeBg);
    window.draw(LevelScreen);
}