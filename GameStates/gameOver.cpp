#include "gameOver.hpp"

GameOverState::GameOverState(sf::RenderWindow& windowp, GameFont& fontsp, ResourceManager& resourcemanagerp, GameState state)
:GameStateBase(windowp, fontsp, resourcemanagerp, state),
gameOverText("Game Over", fonts.arial, sf::Color::White)
{
    cContainer.add(gameOverText);
    mainScreen.add(cContainer);
    resize();
}

void GameOverState::resize(){
    sf::Vector2u winSize = window.getSize();
    cContainer.width = winSize.x;
    cContainer.height = winSize.y;
    gameOverText.marginTop = 0.4;
    cContainer.arrange();
}