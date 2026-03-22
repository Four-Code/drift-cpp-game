#include "leveleditor.hpp"
#include <iostream>
#include "playing.hpp"

LevelEditorGameState::LevelEditorGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara)
:window(windowPara),
fonts(fontsPara),
resourcemanager(resourcemanagerpara),
addObstacle(sf::Color(237, 229, 138), 80, 50, "+", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    Obstacle obstacle(0.08*window.getSize().x, 0.05*window.getSize().y, sf::Color::Blue, std::vector<PatternStep>{});
    obstacle.vx = -200;
    obstacle.x = 1200;
    obstacle.y = 100;
    obstacles.push_back(obstacle);
    std::cout<<obstacles.size()<<std::endl;
}),
play(sf::Color(255, 255, 255), 80, 50, "P", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    isPlaying = true;
}),
pause(sf::Color(255, 255, 255), 80, 50, "||", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    isPlaying = false;
}),
revind(sf::Color(255, 255, 255), 80, 50, "<<", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    
})
{
    resourcemanager.loadplayingBg();

    controls.add(play);
    controls.add(pause);
    controls.add(revind);
    controls.add(addObstacle);
    controls.autoPosition = true;

    // cContainer.add(pause);
    // cContainer.add(play);
    // cContainer.add(addObstacle);

    cContainer.add(controls);

    // levelEditorScreen.add(addObstacle);
    levelEditorScreen.add(cContainer);

    eventHandler.addButton(addObstacle);
    eventHandler.addButton(play);
    eventHandler.addButton(pause);
    eventHandler.addButton(revind);
}
void LevelEditorGameState::show(float dt, double& leftovertime){
    window.draw(resourcemanager.playingBg);
    levelEditorScreen.draw(window);

    if (isPlaying){
        leftovertime += dt;
        while (leftovertime >= PHYSICS_TIME_STEP){
            for (int i = 0; i < obstacles.size(); i++){
                update(obstacles[i]);
            }
            leftovertime -= PHYSICS_TIME_STEP;
            
        }
    }
    
    for (int i = 0; i < obstacles.size(); i++){
        obstacles[i].shape.setPosition(obstacles[i].x, obstacles[i].y);
        window.draw(obstacles[i].shape);
    }
    
}
void LevelEditorGameState::resize(){
    sf::Vector2u winSize = window.getSize();
    float factorW = winSize.x / resourcemanager.homeBg.getLocalBounds().width;
    float factorH = winSize.y / resourcemanager.homeBg.getLocalBounds().height;
    resourcemanager.playingBg.setScale(sf::Vector2f(factorW, factorH));

    play.setPosition(sf::Vector2f(-0.08*winSize.x, 0));
    pause.setPosition(sf::Vector2f(0, 0));
    revind.setPosition(sf::Vector2f(0.08*winSize.x, 0));

    controls.width = 0.3*winSize.x;
    controls.marginTop = 0.8;


    cContainer.width = winSize.x;
    cContainer.height = winSize.y;
    cContainer.setPosition(sf::Vector2f(0, 0));
    cContainer.arrange();
}