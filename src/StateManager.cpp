#include "StateManager.hpp"
#include "GameStates/GameStateBase.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>

void StateManager::show(sf::RenderTarget& target, float dt){
    for(auto& state: states){
        if (state->ID == currentState){
            if (!state->requestChange.has_value()){
                state->show(target, dt);
            }
            else{
                currentState = state->requestChange.value();
                state->requestChange.reset();
            }
        }
    }
}
GameState StateManager::returnCurrentState(){
    return currentState;
}

void StateManager::handleEvent(const std::optional<sf::Event>& event){
        for(auto& state: states){
        if (state->ID == currentState){
            for (auto& element : state->parentContainer.elements){
                element->handleEvent(event);
            }
        }
    }
}