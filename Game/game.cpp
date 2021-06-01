#include "game.hpp"

using namespace game;

Game::Game(const int &windowWidth, const int &windowHeight) : player(windowWidth, windowHeight)
{
    score = 0;
    lives = 1;
}