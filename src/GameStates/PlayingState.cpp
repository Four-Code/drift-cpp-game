#include "GameStates/PlayingState.hpp"
#include "GameObjects/Balloon.hpp"
#include "GameObjects/Obstacles/Needle.hpp"
#include "GameStates/GameStateBase.hpp"
#include "UI/Label.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>
#include <utility>

void PlayingState::init(GameFont& gameFonts){
    GameStateBase::ID = GameState::Playing;
    auto balloon = std::make_unique<Balloon>();
    balloon->radius = 4;
    balloon->Position = {10, 50};
    balloon->Acceleration = {0, -50};
    physicsobjects.push_back(std::move(balloon));
    auto needle = std::make_unique<Needle>();
    needle->Position = {100, 50};
    needle->Velocity = {-50, 0};
    physicsobjects.push_back(std::move(needle));
}

void PlayingState::show(sf::RenderTarget& target, float dt){
    leftovertime += dt;
    while (leftovertime >= PHYSICS_STEP_TIME) {
        for (auto& obj: physicsobjects){
            obj->integrate(PHYSICS_STEP_TIME);
        }
        leftovertime -= PHYSICS_STEP_TIME;
    }

    for (auto& obj: physicsobjects){
        obj->draw(target);
    }
}