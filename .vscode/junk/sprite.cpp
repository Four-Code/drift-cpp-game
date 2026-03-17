#include <iostream>
#include <SFML/Graphics.hpp>




int main(){
    sf::RenderWindow window(sf::VideoMode(600, 600), "Sprite Animation");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("balloonSprite.png")){
        std::cout<<"LooL"<<std::endl;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }   
        }
        
        window.clear(sf::Color(0, 204, 255));
        window.draw(sprite);
        window.display();
    }
    
    return 0;
}