#include "snake.hpp"
using namespace snake;

// this means the maximum length of snake can be 100.
const int Snake::maxLength = 100;

Snake::Snake(const int &windowWidth, const int &windowHeight) : windowWidth(windowWidth), windowHeight(windowHeight)
{
    //FIXME: set length to 2 maybe at start.
    length = 5;
    eachPart = new sf::RectangleShape[Snake::maxLength];
    head = eachPart;
    direction = RIGHT;
}

Snake::Direction Snake::getDirection() const
{
    return direction;
};

void Snake::setDirection(sf::Keyboard::Key key)
{
    switch (key)
    {
    case sf::Keyboard::Up:
        direction = UP;
        break;
    case sf::Keyboard::Down:
        direction = DOWN;
        break;
    case sf::Keyboard::Right:
        direction = RIGHT;
        break;
    case sf::Keyboard::Left:
        direction = LEFT;
        break;
    }
}
// makes the initial drawable snake
bool Snake::makeInitialSnake()
{
    std::cout << windowWidth << ", " << windowHeight << std::endl;
    // making the head of snake
    *head = sf::RectangleShape(sf::Vector2f(sizeOfEachPart.x, sizeOfEachPart.y));
    (*head).setFillColor(sf::Color::Green);
    // setting the position of head to center of window initially.
    (*head).setPosition(windowWidth / 2.0, windowHeight / 2.0);

    // FIXME: see about the return of the const & type by getPosition func.
    // eachPartCoordinate[0] = head.getPosition();

    // making body of the snake. ( started from index = 1, as head = 0 )
    for (int i = 1; i < length; i++)
    {
        eachPart[i] = sf::RectangleShape(sf::Vector2f(sizeOfEachPart.x, sizeOfEachPart.y));
        ;
        eachPart[i].setFillColor(sf::Color::Magenta);
        // shifting new part to the left of the previous part initially.
        eachPart[i].setPosition(eachPart[i - 1].getPosition().x - sizeOfEachPart.x, eachPart[i - 1].getPosition().y);
    }
    return true;
}
// used to just render the snake
void Snake::renderSnake(sf::RenderWindow &window)
{
    for (int i = 0; i < length; i++)
    {
        window.draw(eachPart[i]);
    }
}
