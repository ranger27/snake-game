#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics.hpp>
#include "../randomLibrary/random.hpp"

namespace food
{
    class Food
    {
        const int &windowWidth;
        const int &windowHeight;
        // A part of the outside of the size should be invisible
        sf::Vector2u size = sf::Vector2u(40, 40);

        // to be improved further so that random location
        // doesn't fall into body of snake
        sf::Vector2f findALocation();

        // every info about food may be here except size,window info
        sf::RectangleShape food;

        void createFood();

    public:
        // DATA MEMBERS:

        int outLineThickness = -8;
        // FUNCTIONS

        // getter for the food data member
        sf::RectangleShape getFood();

        // Creates a complete food, internally calls createFood and findALocation.
        // After creating food, calling renderFood is enough for its use
        Food(const int &windowWidth, const int &windowHeight);
        ~Food() {}
        sf::Vector2u getSize() const;
        // used to just render the snake
        void renderFood(sf::RenderWindow &window);
    };
}

#endif