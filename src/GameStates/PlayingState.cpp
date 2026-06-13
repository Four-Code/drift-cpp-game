#include "GameStates/PlayingState.hpp"
#include "GameStates/GameStateBase.hpp"
#include "UI/Label.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void PlayingState::init(GameFont& gameFonts){
    GameStateBase::ID = GameState::Playing;
    parentContainer.addElement<Label>("Playing", gameFonts.base, 10);
}

void PlayingState::show(sf::RenderTarget& target, float dt){
    parentContainer.draw(target);
}