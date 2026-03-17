#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "gameState.hpp"
#include "../gameFont.hpp"
#include "../UIElements/button.hpp"
#include "../resourceManager.hpp"
#include "../UIElements/text.hpp"
#include "UIContainer.hpp"
#include "centerContainer.hpp"
#include "../eventHandler.hpp"

class LevelGameState{
    public:
    std::optional<GameState> requestState;
    sf::RenderWindow& window;
    GameFont& fonts;

    ResourceManager resourcemanager;

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

    UIContainer LevelScreen;
    CenterContainer centercontainer1;
    CenterContainer centercontainer2;

    EventHandler eventHandler;    

    int requestLevelNo;


    LevelGameState(sf::RenderWindow& window, GameFont& gamefontpara, ResourceManager& resourcemanagerpara);

    void show();
    void resize();

};