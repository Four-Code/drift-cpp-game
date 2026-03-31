#include "resourceManager.hpp"

void ResourceManager::loadHomeBg(){
    if (!loadedHomeBg){
        homeBgTexture.loadFromFile("Resources/homebg.png");
        homeBg.setTexture(homeBgTexture);
        loadedHomeBg = true;
    }
}

void ResourceManager::loadplayingBg(){
    if (!loadedplayingBg){
        playingBgTexture.loadFromFile("Resources/playingBg.png");
        playingBg.setTexture(playingBgTexture);
        loadedplayingBg = true;
    }
}

void ResourceManager::loadhomeBalloon(){
    if (!loadedhomeBalloon){
        homeBalloonTexture.loadFromFile("Resources/homeBalloon.png");
        loadedhomeBalloon = true;
        homeBalloonTexture.setSmooth(true);
    }
}

void ResourceManager::loadhomeCloud(){
    if (!loadedhomeCloud){
        homeCloudTexture.loadFromFile("Resources/homeCloud.png");
        loadedhomeCloud = true;
        homeCloudTexture.setSmooth(true);
    }
}

void ResourceManager::loadNeedle(){
    if (!loadedNeedle){
        needleTexture.loadFromFile("Resources/needle.png");
        loadedNeedle = true;
        needleTexture.setSmooth(true);
    }
}

void ResourceManager::loadHomeNeedle(){
    if (!loadedHomeNeedle){
        homeNeedleTexture.loadFromFile("Resources/homeNeedle.png");
        loadedHomeNeedle = true;
        homeNeedleTexture.setSmooth(true);
    }
}