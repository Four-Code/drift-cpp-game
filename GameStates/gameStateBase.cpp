#include "gameStateBase.hpp"

GameStateBase::GameStateBase(sf::RenderWindow& window, GameFont& fonts, ResourceManager& resourcemanager, GameState state)
:window(window), fonts(fonts), resourcemanager(resourcemanager), state(state)
{}

void GameStateBase::show(){
    window.clear();
    mainScreen.draw(window);
}

void GameStateBase::resize(){};

void GameStateBase::startTransitionOut(){
    transitionstate = TransitionState::notOver; 
    isTransitionOut=true;
    
}

void GameStateBase::startTransitionIn(){
    transitionstate = TransitionState::notOver; 
    isTransitionIn=true;
}

void GameStateBase::updateTransition(float dt){
    transitionstate = TransitionState::over;
    isTransitionIn = false;
    isTransitionOut = false;
};

void GameStateBase::resetTransitionFlags(){
    transitionstate.reset();
    requestState.reset();
    isTransitionIn = false;
    isTransitionOut = false;
}