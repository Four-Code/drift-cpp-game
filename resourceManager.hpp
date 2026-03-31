#pragma once
#include <SFML/Graphics.hpp>


class ResourceManager{
    public:
    sf::Sprite homeBg;
    void loadHomeBg();
    bool loadedHomeBg = false;

    sf::Sprite playingBg;
    void loadplayingBg();
    bool loadedplayingBg = false;
    
    void loadhomeBalloon();
    bool loadedhomeBalloon = false;

    void loadhomeCloud();
    bool loadedhomeCloud = false;

    void loadNeedle();
    bool loadedNeedle = false;

    void loadHomeNeedle();
    bool loadedHomeNeedle = false;

    sf::Texture homeBgTexture;
    sf::Texture playingBgTexture;
    sf::Texture homeBalloonTexture;
    sf::Texture homeCloudTexture;
    sf::Texture homeNeedleTexture;
    sf::Texture needleTexture;
};