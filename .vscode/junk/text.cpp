#include <iostream>
#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Text");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("ARIBLK.TTF");

    sf::Text hello("Hello", font, 100);
    hello.setPosition(sf::Vector2f(450, 200));

    std::cout<< hello.getLocalBounds().getSize().y<<std::endl;

    while (window.isOpen()){
        sf::Event event;
        if (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){window.close();}
        }
        window.clear();
        window.draw(hello);
        window.display();
    }

    
    return 0;
}