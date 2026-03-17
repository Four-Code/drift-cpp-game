#include "balloon.hpp"
#include "SFML/Graphics.hpp"

Balloon::Balloon(float radius, sf::Color color){
        this->color = color;
        this->radius = radius;
        shape.setRadius(this->radius);
        shape.setFillColor(color);
}

void Balloon::setRadius(float radius){
        this->radius = radius;
        shape.setRadius(this->radius);
}

void Balloon:: setColor(sf::Color color){
        this->color = color;
        shape.setFillColor(color);
}

void Balloon:: update(float dt){
        PhysicsObject::integrate(dt);

        if (this->isJump){
        //impulse
        int impulseValue = -250;
        if (this->isShift){
            impulseValue = -500;
        }
        else if (this->isCtrl && !this->isShift){
            impulseValue = -150;
        }
        
        this->vy = impulseValue;
        
        this->isJump = false;
    }
}