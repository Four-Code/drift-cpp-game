#pragma once
#include <vector>
#include "obstacle.hpp"
#include <SFML/Graphics.hpp>

enum GameState{Home, Menu, LoadLevel, Playing, Paused, GameOver, LevelEditor};


struct spawnData{
    float spawnTime;
    float y;
    float vx;
    sf::Color color;
    std::vector<PatternStep> Pattern;
};

class Levels{
    public:
    std::vector<std::vector<spawnData>> levels;
    void loadLevel(int levelNo);
    
};