#include "StateManager.hpp"
#include "GameStates/GameStateBase.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>

void StateManager::show(sf::RenderTarget& target, float dt, const sf::Event& event){
    for(auto& state: states){
        if (state->ID == currentState){
            for (auto& element : state->parentContainer.elements){
                element->handleEvent(event);
            }
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