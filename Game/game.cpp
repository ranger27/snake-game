#include "game.hpp"
#include <iostream>
#include <string>

using namespace game;

Game::Game(const int &windowWidth, const int &windowHeight, sf::Font &font) : player(windowWidth, windowHeight)
{
    score = 0;
    lives = 1;
    createScore(font);
}

bool Game::didPlayerEatFood(food::Food &currentFruit)
{
    // collision detection

    if ((this->player.getterOfHead()->getPosition().x < currentFruit.getFood().getPosition().x + currentFruit.getSize().x and currentFruit.getFood().getPosition().x < player.getterOfHead()->getPosition().x + player.getSizeOfEachPart().x) and (this->player.getterOfHead()->getPosition().y < currentFruit.getFood().getPosition().y + currentFruit.getSize().y and currentFruit.getFood().getPosition().y < player.getterOfHead()->getPosition().y + player.getSizeOfEachPart().y))
    {
        // food collided with snake
        // i.e. food eaten
        score += 10;
        std::cout << "score= " << score << std::endl;
        // currentFruit.~Food();
        player.increaseSnakeLength();
        return true;
    }
    return false;
}

void Game::createScore(sf::Font &font)
{

    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Red);
}

void Game::renderScore(sf::RenderWindow &window)
{
    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);
}