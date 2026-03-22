#include "playing.hpp"
#include "../physicsObject.hpp"
#include "../balloon.hpp"
#include "../obstacle.hpp"
#include <iostream>


void update(PhysicsObject& obj){
    if (obj.x<1200){
        obj.timeSinceSpawn += PHYSICS_TIME_STEP;
    }
    obj.update(PHYSICS_TIME_STEP);
}


float sqr(float x){
    return x*x;
}

bool checkCollision(const Balloon& balloon, const Obstacle& needle){
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


PlayingGameState::PlayingGameState(sf::RenderWindow& windowPara, GameFont& fontsPara, ResourceManager& resourcemanagerpara)
:window(windowPara),
fonts(fontsPara),
resourcemanager(resourcemanagerpara)
{

}

void PlayingGameState::show(float dt, double& leftoverTime, std::vector<Obstacle>& obstacles, Balloon& player ){
    window.draw(resourcemanager.playingBg);
    for (int i = 0; i < obstacles.size(); i++){
        obstacles[i].shape.setPosition(obstacles[i].x, obstacles[i].y);
    }
    
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

    std::cout<<dt<<std::endl;
    
    player.shape.setPosition(player.x-player.radius, player.y-player.radius);

    
    window.draw(resourcemanager.playingBg);
    window.draw(player.shape);
            
    for (int i = 0; i < obstacles.size(); i++){
        window.draw(obstacles[i].shape);
    }
}

void PlayingGameState::resize(std::vector<Obstacle>& obstacles, Balloon& player){
    sf::Vector2u winSize = window.getSize();
    float factorW = winSize.x / resourcemanager.playingBg.getLocalBounds().width;
    float factorH = winSize.y / resourcemanager.playingBg.getLocalBounds().height;
    resourcemanager.playingBg.setScale(sf::Vector2f(factorW, factorH));

    for (int i = 0; i < obstacles.size(); i++){
        obstacles[i].shape.setSize(sf::Vector2f(obstacles[i].width * winSize.x, obstacles[i].height*winSize.y));
    }
    player.shape.setRadius(player.radius*winSize.x);
}