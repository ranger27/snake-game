#include "game.hpp"
#include <iostream>

using namespace game;

Game::Game(const int &windowWidth, const int &windowHeight) : player(windowWidth, windowHeight)
{
    score = 0;
    lives = 1;
}

bool Game::didPlayerEatFood(food::Food &currentFruit)
{
    // collision detection
    
    if ((this->player.getterOfHead()->getPosition().x <  currentFruit.getFood().getPosition().x + currentFruit.getSize().x and currentFruit.getFood().getPosition().x < player.getterOfHead()->getPosition().x + player.getSizeOfEachPart().x) and (this->player.getterOfHead()->getPosition().y < currentFruit.getFood().getPosition().y + currentFruit.getSize().y and currentFruit.getFood().getPosition().y < player.getterOfHead()->getPosition().y + player.getSizeOfEachPart().y))
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