#include "playing.hpp"
#include "../physicsObject.hpp"
#include "../balloon.hpp"
#include "../obstacle.hpp"
#include <iostream>
#include <cmath>

std::string formatP(double x){
    std::string s = std::to_string(std::trunc(x*100)/100);
    while (!s.empty() && s.back()=='0'){
        s.pop_back();
    }
    return s;
}


void update(PhysicsObject& obj){
    if (obj.x<1200){
        obj.timeSinceSpawn += PHYSICS_TIME_STEP;
    }
    obj.xprev = obj.x;
    obj.yprev = obj.y;
    obj.update(PHYSICS_TIME_STEP);
}


float sqr(float x){
    return x*x;
}

bool checkCollision(const Balloon& balloon, const Needle& needle){
    float closestX = 0.00f;
    float closestY = 0.00f;
    sf::FloatRect needleData = needle.shape.getGlobalBounds();
    sf::FloatRect balloonData = balloon.shape.getGlobalBounds();

    float needlex = needleData.getPosition().x;
    float needley = needleData.getPosition().y;
    float balloonx = balloonData.getPosition().x+balloon.shape.getRadius();
    float balloony = balloonData.getPosition().y+balloon.shape.getRadius();
    float needlewidth = needleData.width;
    float needleheight = needleData.height;
    if (balloonx<=needlex){
        closestX = needlex;
    }
    else if (balloonx >= needlex+needlewidth){
        closestX = needlex + needlewidth;
    }
    else{
        closestX = balloonx;
    }

    if (balloony <= needley){
        closestY = needley;
    }
    else if (balloony >= needley + needleheight){
        closestY = needley + needleheight;
    }
    else{
        closestY = balloony;
    }

    float dsqr = sqr(closestX - balloonx) + sqr(closestY - balloony);

    if (dsqr<=sqr(balloon.shape.getRadius())){
        return true;
    }
    else{
        return false;
    }
    
}


PlayingGameState::PlayingGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara,  Balloon& playerP,  std::vector<Needle>& obstaclesP, GameState state)
:GameStateBase(windowPara, fontsPara, resourcemanagerpara, state), player(playerP), obstacles(obstaclesP),fps("0", fonts.arial, sf::Color::Black)
{
    fps.setPosition({100, 50});
}

void PlayingGameState::play(float dt, double& leftoverTime){
    fps.setText(formatP(1.0f/dt));
    window.draw(resourcemanager.playingBg);
    fps.draw(window);
    
    if (!firstframe){
        leftoverTime += dt;
        while (leftoverTime>=PHYSICS_TIME_STEP){           
            update(player);
            for (int i = 0; i < obstacles.size(); i++){
                update(obstacles[i]);
            }
            
            for (int i = 0; i < obstacles.size(); i++){
                if (checkCollision(player, obstacles[i])){alive=false;}
            }
            leftoverTime -= PHYSICS_TIME_STEP;
        }
    }
    else{firstframe=false;}


    float alpha = leftoverTime/PHYSICS_TIME_STEP;
    float prenderX = player.xprev + (player.x - player.xprev) * alpha;
    float prenderY = player.yprev + (player.y - player.yprev) * alpha;

    player.shape.setPosition(prenderX - player.radius, prenderY - player.radius);

    for (int i = 0; i < obstacles.size(); i++){
        float renderX = obstacles[i].xprev + (obstacles[i].x - obstacles[i].xprev) * alpha;
        float renderY = obstacles[i].yprev + (obstacles[i].y - obstacles[i].yprev) * alpha;

        obstacles[i].shape.setPosition(sf::Vector2f(renderX, renderY));
        obstacles[i].show(window);
    }
    


    window.draw(player.shape);
}

void PlayingGameState::resize(){
    sf::Vector2u winSize = window.getSize();
    float factorW = winSize.x / resourcemanager.playingBg.getLocalBounds().width;
    float factorH = winSize.y / resourcemanager.playingBg.getLocalBounds().height;
    resourcemanager.playingBg.setScale(sf::Vector2f(factorW, factorH));

    for (int i = 0; i < obstacles.size(); i++){
        obstacles[i].shape.setSize(sf::Vector2f(obstacles[i].width * winSize.x, obstacles[i].height*winSize.y));
    }
    player.shape.setRadius(player.radius*winSize.x);
}

void PlayingGameState::show(){
    
}