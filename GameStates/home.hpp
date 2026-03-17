#pragma once
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "UIContainer.hpp"
#include "../UIElements/button.hpp"
#include "../eventHandler.hpp"
#include "gameState.hpp"
#include <optional>
#include "../resourceManager.hpp"
#include "../UIElements/text.hpp"
#include "centerContainer.hpp"
#include <vector>

class HomeGameState{
    public:
    float buttonFactor;
    std::optional<GameState> requestState;
    sf::RenderWindow& window;
    GameFont& fonts;
    UIText versionNumberText;
    ResourceManager resourcemanager;
    UIContainer homeScreen;
    GUIButton start;
    GUIButton level;
    EventHandler eventHandler;
    CenterContainer centercontainer;


    // std::vector<UIElement*> elements;

    
    
    HomeGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara);
    void resize();
    void show();
};