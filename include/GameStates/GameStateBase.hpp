#pragma once

#include "UI/Container.hpp"
class GameStateBase{
    public:
    Container parentContainer;
    virtual void init()=0;
    virtual void show(float dt)=0;
};