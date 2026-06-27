#include "GameStates/HomeState.hpp"
#include "GameStates/PlayingState.hpp"
#include "StateManager.hpp"
#include "UI/GameFonts.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <optional>

int screenWidth = 1200;
int screenHeight = 800;

int main(){
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 6;
    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(screenWidth), static_cast<unsigned int>(screenHeight)}), "Drift v2.0", sf::Style::Default, sf::State::Windowed, settings);

    GameFont gameFonts;
    gameFonts.base.openFromFile("resources/fonts/IosevkaCharonMono-BoldItalic.ttf");

    StateManager statemanager;

    HomeState& homestate = statemanager.addState<HomeState>();
    homestate.init(gameFonts);

    PlayingState& playingstate = statemanager.addState<PlayingState>();
    playingstate.init(gameFonts);

    sf::Clock clock;
    float dt = 0;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            statemanager.handleEvent(event);
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }        
        }
        dt = clock.restart().asSeconds();
        window.clear();
        statemanager.show(window, dt);
        window.display();
    }
    return 0;
}