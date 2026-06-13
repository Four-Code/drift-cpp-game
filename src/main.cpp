#include "GameObjects/Balloon.hpp"
#include "GameObjects/PhysicsObject.hpp"
#include "GameStates/HomeState.hpp"
#include "GameStates/PlayingState.hpp"
#include "StateManager.hpp"
#include "UI/Button.hpp"
#include "UI/GameFonts.hpp"
#include "UI/Label.hpp"
#include "UI/Container.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

int screenWidth = 1200;
int screenHeight = 800;
const float PHYSICS_STEP_TIME = 1/60.0f;

int main(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Drift v2.0", sf::Style::Default, settings);

    GameFont gameFonts;
    gameFonts.base.loadFromFile("resources/fonts/IosevkaCharonMono-BoldItalic.ttf");

    StateManager statemanager;

    HomeState& homestate = statemanager.addState<HomeState>();
    homestate.init(gameFonts);

    PlayingState& playingstate = statemanager.addState<PlayingState>();
    playingstate.init(gameFonts);

    Balloon balloon;
    balloon.radius = convertLengthToPixel(4);
    balloon.Position = {20, 20};
    balloon.Velocity = {1, 1};

    sf::Clock clock;
    float dt = 0;
    double leftovertime = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:{
                    window.close();
                }
                
            }        
        }
        dt = clock.restart().asSeconds();
        leftovertime += dt;
        while (leftovertime>PHYSICS_STEP_TIME) {
            balloon.integrate(PHYSICS_STEP_TIME);
            leftovertime -= dt;
        }
        window.clear();
        statemanager.show(window, dt, event);
        balloon.draw(window);
        window.display();
    }
    return 0;
}