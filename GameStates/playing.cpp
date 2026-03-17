#include "playing.hpp"
#include "../physicsObject.hpp"
#include "../balloon.hpp"
#include "../obstacle.hpp"

const float PHYSICS_TIME_STEP = 0.0166667;

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
    if (balloon.x<=needle.x){
        closestX = needle.x;
    }
    else if (balloon.x >= needle.x+needle.width){
        closestX = needle.x + needle.width;
    }
    else{
        closestX = balloon.x;
    }

    if (balloon.y <= needle.y){
        closestY = needle.y;
    }
    else if (balloon.y >= needle.y + needle.height){
        closestY = needle.y + needle.height;
    }
    else{
        closestY = balloon.y;
    }

    float dsqr = sqr(closestX - balloon.x) + sqr(closestY - balloon.y);

    if (dsqr<=sqr(balloon.radius)){
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
    float factor = window.getSize().x / resourcemanager.homeBg.getLocalBounds().width;
    resourcemanager.homeBg.setScale(sf::Vector2f(factor, factor));
    window.draw(resourcemanager.playingBg);
    
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
    
    player.shape.setPosition(player.x-player.radius, player.y-player.radius);
    for (int i = 0; i < obstacles.size(); i++){
        obstacles[i].shape.setPosition(obstacles[i].x, obstacles[i].y);
    }
    
    window.draw(resourcemanager.playingBg);
    // window.clear(sf::Color(71, 71, 71));
    window.draw(player.shape);
            
    for (int i = 0; i < obstacles.size(); i++){
        window.draw(obstacles[i].shape);
    }
}