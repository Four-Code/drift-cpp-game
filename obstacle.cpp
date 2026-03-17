#include "obstacle.hpp"
#include "physicsObject.hpp"
#include <SFML/Graphics.hpp>


Obstacle:: Obstacle(float width, float height, sf::Color color, std::vector<PatternStep> Pattern){
        this->width = width;
        this->height = height;
        this->color = color;
        shape.setSize(sf::Vector2f(this->width, this->height));
        shape.setFillColor(color);
    }
void Obstacle::executePattern(){
    for (PatternStep patternstep: Pattern){
        if( timeSinceSpawn >= patternstep.triggerTime){
            switch (patternstep.actionType){
                case ActionType::SetVx :{
                vx = patternstep.value;
                break;
                }
                case ActionType::SetVy:{
                    vy = patternstep.value;
                    break;
                }
                case ActionType::Destory:{
                    break;
                }
            }

        }
    }
}
void Obstacle::update(float dt){
    PhysicsObject::integrate(dt);
    executePattern();
}