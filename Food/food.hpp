#ifndef FOOD_HPP
#define FOOD_HPP

#include <SFML/Graphics.hpp>

namespace food{
    class Food{
        // location
        sf::Vector2u location;
public:
        Food(){
            location = findALocation();
        }

        sf::Vector2u findALocation(){
            // to be implemented
            return sf::Vector2u(1,3);
        }
    };
}

#endif