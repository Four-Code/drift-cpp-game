#pragma once
#include <SFML/Graphics.hpp>


class ResourceManager{
    public:
    sf::Sprite homeBg;
    void loadHomeBg();
    bool loadedHomeBg = false;

    sf::Sprite buttonSprite;
    void loadButtonSprite();
    bool loadedButtonSprite = false;

    sf::Sprite playingBg;
    void loadplayingBg();
    bool loadedplayingBg = false;
    
    sf::Texture homeBgTexture;
    sf::Texture buttonTexture;
    sf::Texture playingBgTexture;
    
};