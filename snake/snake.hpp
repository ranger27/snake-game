#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

// using namespace std;

namespace snake
{
    class Snake
    {
        // current length of snake including the head.
        int length;
        // this means the maximum length of snake can be 100.
        static const int maxLength;
        // size of each part of snake is 40*40
        sf::Vector2u sizeOfEachPart = sf::Vector2u(40, 40);
        
        // every info of each part.
        sf::RectangleShape *eachPart;
        // constant pointer/reference to the head of snake.
        sf::RectangleShape *head;
        // width and height of window
        const int &windowWidth;
        const int &windowHeight;
        enum Direction
        {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        Direction currDirection;
        //FIXME: may be delete this or use it
        Direction prevDirection;

    public:
        Snake(const int &windowWidth, const int &windowHeight);
        Direction getCurrentDirection() const;
        void setCurrentDirection(sf::Keyboard::Key key);
        bool makeInitialSnake();
        void renderSnake(sf::RenderWindow & window);
        void moveSnake();
    };
    
}
#endif