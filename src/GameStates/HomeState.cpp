#include "GameStates/HomeState.hpp"
#include "GameStates/GameStateBase.hpp"
#include "UI/Button.hpp"
#include "UI/Label.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void HomeState::init(GameFont& gameFonts){
    GameStateBase::ID = GameState::Home;
    Label& title = GameStateBase::parentContainer.addElement<Label>("Drift", gameFonts.base, 3);
    Button& button = GameStateBase::parentContainer.addElement<Button>("Start", gameFonts.base, 150, 40, [&]{
        GameStateBase::requestChange = GameState::Playing;
    });
    button.setPosition({500, 300});
    title.upDateFontSize(80);
    title.setPosition({500, 100});
}

void HomeState::show(sf::RenderTarget& target, float dt){
    GameStateBase::parentContainer.draw(target);
}

