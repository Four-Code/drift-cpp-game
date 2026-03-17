#include "physicsObject.hpp"

void PhysicsObject::integrate(float dt){
    vx += ax * dt;
    vy += ay * dt;
    x += vx * dt;
    y += vy * dt;
}

void PhysicsObject::update(float dt){}