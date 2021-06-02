#include "food.hpp"
#include <iostream>

using namespace food;
// to be improved further so that random location
// doesn't fall into body of snake
sf::Vector2f Food::findALocation()
{
    // random library usage
    using Random = effolkronium::random_static;

    // randomly selecting a space for food in the window ( in width = 0 to
    // width-size.x ) same for height case too.
    return sf::Vector2f(int(Random::get(0, windowWidth - (int)size.x) / (float)size.x) * (size.x), int(Random::get(0, windowHeight - (int)size.y) / (float)size.y) * (size.y));
}

Food::Food(int windowWidth, int windowHeight) : windowWidth(windowWidth), windowHeight(windowHeight)
{
    createFood();
}

// makes a complete food ( square ) with its random position also set
// by caling findALocation method
void Food::createFood()
{
    food = sf::RectangleShape(sf::Vector2f(size.x, size.y));
    food.setFillColor(sf::Color::Red);
    food.setOutlineThickness(outLineThickness);
    food.setOutlineColor(sf::Color::Cyan);
    food.setPosition(findALocation());
}

// used to just render the snake
void Food::renderFood(sf::RenderWindow &window)
{
    window.draw(food);
}

sf::RectangleShape Food::getFood()
{
    return this->food;
}

sf::Vector2u Food::getSize() const
{
    return size;
}