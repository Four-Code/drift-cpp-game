#include "resourceManager.hpp"

void ResourceManager::loadHomeBg(){
    if (!loadedHomeBg){
        homeBgTexture.loadFromFile("Resources/homebg.png");
        homeBg.setTexture(homeBgTexture);
        loadedHomeBg = true;
    }
}

void ResourceManager::loadButtonSprite(){
    if (!loadedButtonSprite){
        buttonTexture.loadFromFile("Resources/button.png");
        buttonSprite.setTexture(buttonTexture);
        loadedButtonSprite = true;
    }
}

void ResourceManager::loadplayingBg(){
    if (!loadedplayingBg){
        playingBgTexture.loadFromFile("Resources/playingBg.png");
        playingBg.setTexture(playingBgTexture);
        loadedplayingBg = true;
    }
}