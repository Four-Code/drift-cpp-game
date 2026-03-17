#pragma once

//Generic Physics Object
class PhysicsObject{
    public:
        float x = 100.00f;
        float y = 100.00f;
        float vx = 0;
        float vy = 0;
        float ax = 0;
        float ay = 0;
        float timeSinceSpawn = 0;
        void integrate(float dt);
        virtual void update(float dt);
};