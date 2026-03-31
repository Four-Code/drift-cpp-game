#include "leveleditor.hpp"
#include <iostream>
#include "playing.hpp"
#include <cmath>

std::string format(double x){
    std::string s = std::to_string(std::trunc(x*100)/100);
    while (!s.empty() && s.back()=='0'){
        s.pop_back();
    }
    return s;
}



EditableObstacle::EditableObstacle(float width, float height, sf::Color color, std::function<void()> onClick)
:Obstacle(width, height, std::vector<PatternStep>{}),
shape(width, height, color, onClick)
{

}
void EditableObstacle::show(sf::RenderWindow& window){
    shape.draw(window);
}

LevelEditorGameState::LevelEditorGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara, GameState state)
:GameStateBase(windowPara, fontsPara, resourcemanagerpara, state),
addObstacle(sf::Color(237, 229, 138), 80, 50, "+", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    EditableObstacle obstacle(0.08*window.getSize().x, 0.05*window.getSize().y, sf::Color::Blue, [&]{
        std::cout << "pressed obstacle"<<std::endl;
    });
    obstacle.vx = -200;
    obstacle.x = 1200;
    obstacle.y = 100;
    obstacles.push_back(obstacle);
}),
play(sf::Color(255, 255, 255), 80, 50, "P", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    isPlaying = true;
}),
pause(sf::Color(255, 255, 255), 80, 50, "||", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    isPlaying = false;
}),
revind(sf::Color(255, 255, 255), 80, 50, "<<", fonts.arial, sf::Vector2f(0, 0), resourcemanager, [&]{
    obstacles[0].vx *= -1;
    direction = -1;
}),
editorTimeDisplay(std::to_string(editorTime), fonts.arial, sf::Color::Black)
{
    resourcemanager.loadplayingBg();

    controls.add(play);
    controls.add(pause);
    controls.add(revind);
    controls.add(addObstacle);
    controls.autoPosition = true;

    cContainer.add(controls);

    mainScreen.add(editorTimeDisplay);
    mainScreen.add(cContainer);
    

    eventHandler.addButton(addObstacle);
    eventHandler.addButton(play);
    eventHandler.addButton(pause);
    eventHandler.addButton(revind);
}
void LevelEditorGameState::show(float dt, double& leftovertime){
    window.draw(resourcemanager.playingBg);
    mainScreen.draw(window);
    editorTimeDisplay.setText("Time: " +format(editorTime));
    
    if (isPlaying){
        editorTime = editorTime + direction* dt;
        leftovertime += dt;
        while (leftovertime >= PHYSICS_TIME_STEP){
            for (int i = 0; i < obstacles.size(); i++){
                update(obstacles[i]);
            }
            leftovertime -= PHYSICS_TIME_STEP;
            
        }
    }
    
    for (int i = 0; i < obstacles.size(); i++){
        obstacles[i].shape.setPosition(sf::Vector2f(obstacles[i].x, obstacles[i].y));
        obstacles[i].shape.draw(window);
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

    editorTimeDisplay.setPosition(sf::Vector2f(100, 50));
}