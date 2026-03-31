#pragma once
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../UIElements/button.hpp"
#include "../resourceManager.hpp"
#include "../UIElements/text.hpp"
#include "UIContainer.hpp"
#include "centerContainer.hpp"
#include "../eventHandler.hpp"
#include "../levelSys.hpp"
#include "gameStateBase.hpp"

class LevelGameState: public GameStateBase{
    public:

    float buttonFactor;
    float btnWidth;
    float btnHeight;

    GUIButton level1;
    GUIButton level2;
    GUIButton level3;
    GUIButton level4;
    GUIButton level5;
    GUIButton level6;

    UIText levels;

    CenterContainer centercontainer1;
    CenterContainer centercontainer2;   
    CenterContainer levelcentercontainer;   


    int requestLevelNo;
    float transitionSpeed;


    LevelGameState(sf::RenderWindow& window, GameFont& gamefontpara, ResourceManager& resourcemanagerpara, GameState state);

    void show() override;
    void resize() override;
    void updateTransition(float dt) override;

};