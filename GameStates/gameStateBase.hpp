#pragma once
#include <SFML/Graphics.hpp>
#include "../gameFont.hpp"
#include "../resourceManager.hpp"
#include "UIContainer.hpp"
#include "../eventHandler.hpp"
#include "../levelSys.hpp"
#include <optional>

enum TransitionState{over, notOver};

class GameStateBase{
    public:
    GameState state;
    sf::RenderWindow& window;
    GameFont& fonts;
    ResourceManager& resourcemanager;
    EventHandler eventHandler;
    UIContainer mainScreen;
    bool isTransitionOut;
    bool isTransitionIn;
    std::optional<TransitionState> transitionstate;
    std::optional<GameState> requestState;


    GameStateBase(sf::RenderWindow& window, GameFont& fonts, ResourceManager& resourcemanager, GameState state);
    virtual void show();
    virtual void resize();
    virtual void startTransitionOut();
    virtual void startTransitionIn();
    virtual void updateTransition(float dt);
    void resetTransitionFlags();

};