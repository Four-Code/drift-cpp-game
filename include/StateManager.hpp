#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <optional>
#include <utility>
#include <vector>
#include "GameStates/GameStateBase.hpp"

class StateManager{
    public:
    std::vector<std::unique_ptr<GameStateBase>> states;
    template<typename T>
    T& addState(){
        auto ptr = std::make_unique<T>();
        T& ref = *ptr;
        states.push_back(std::move(ptr));
        return ref;
    }
    void show(sf::RenderTarget& target, float dt);
    void handleEvent(const std::optional<sf::Event>& event);
    GameState returnCurrentState();
    private:
    GameState currentState = GameState::Home;
};