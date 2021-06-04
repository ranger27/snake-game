#include "snake.hpp"
using namespace snake;

// this means the maximum length of snake can be 100.
const int Snake::maxLength = 100;

Snake::Snake(const int &windowWidth, const int &windowHeight) : windowWidth(windowWidth), windowHeight(windowHeight)
{
    //FIXME: set length to 2 maybe at start.
    length = 2;
    lives = 1;
    eachPart = new sf::RectangleShape[Snake::maxLength];
    head = eachPart;
    currDirection = RIGHT;
    // prevDirection = RIGHT;
}


Snake::Direction Snake::getCurrentDirection() const
{
    return currDirection;
};

void Snake::setCurrentDirection(sf::Keyboard::Key key)
{
    // immediate straight turn should not happen
    if (currDirection == UP and key == sf::Keyboard::Down || currDirection == DOWN and key == sf::Keyboard::Up ||
        currDirection == RIGHT and key == sf::Keyboard::Left ||
        currDirection == LEFT and key == sf::Keyboard::Right)
    {
        return;
    }

    // prevDirection = currDirection;
    switch (key)
    {
    case sf::Keyboard::Up:
        currDirection = UP;
        break;
    case sf::Keyboard::Down:
        currDirection = DOWN;
        break;
    case sf::Keyboard::Right:
        currDirection = RIGHT;
        break;
    case sf::Keyboard::Left:
        currDirection = LEFT;
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
// should be called after we update direction, so that moves in actual direction.
void Snake::moveSnake()
{
    Direction dir = getCurrentDirection();
    sf::Vector2f tempPos1 = head->getPosition();
    switch (dir)
    {
    case UP:
        if (head->getPosition().y - sizeOfEachPart.y < 0)
        {
            head->setPosition(head->getPosition().x, windowHeight - sizeOfEachPart.y);
        }
        else
        {
            head->setPosition(head->getPosition().x, head->getPosition().y - sizeOfEachPart.y);
        }

        break;

    case DOWN:
        if (head->getPosition().y + sizeOfEachPart.y >= windowHeight)
        {
            head->setPosition(head->getPosition().x, 0);
        }
        else
        {
            head->setPosition(head->getPosition().x, head->getPosition().y + sizeOfEachPart.y);
        }
        break;

    case RIGHT:
        if (head->getPosition().x + sizeOfEachPart.x >= windowWidth)
        {
            head->setPosition(0, head->getPosition().y);
        }
        else
        {
            head->setPosition(head->getPosition().x + sizeOfEachPart.x, head->getPosition().y);
        }
        break;

    case LEFT:
        if (head->getPosition().x - sizeOfEachPart.x < 0)
        {
            head->setPosition(windowWidth - sizeOfEachPart.x, head->getPosition().y);
        }
        else
        {
            head->setPosition(head->getPosition().x - sizeOfEachPart.x, head->getPosition().y);
        }
        break;
    }

    // head = 0, which is done above so now looping from i = 1
    for (int i = 1; i < length; i++)
    {
        sf::Vector2f tempPos2 = eachPart[i].getPosition();
        eachPart[i].setPosition(tempPos1);
        tempPos1 = tempPos2;
    }
    // TODO: Temppos1 of last segment is vvi for the addition of a part
    // after food is eaten.
    posOfLastPart = tempPos1;
}

sf::RectangleShape *Snake::getterOfHead() const
{
    return head;
}

sf::Vector2u Snake::getSizeOfEachPart() const
{
    return sizeOfEachPart;
}
// increaes the length of the snake after the food is eaten.
void Snake::increaseSnakeLength()
{
    length += 1;
    eachPart[length - 1] = sf::RectangleShape(sf::Vector2f(sizeOfEachPart.x, sizeOfEachPart.y));

    eachPart[length - 1].setFillColor(sf::Color::Magenta);
    // shifting new part to the left of the previous part initially.
    eachPart[length - 1].setPosition(posOfLastPart);
}

bool Snake::didSnakeHitItself()
{
    // starting from i = 1 not i =0 because head has index = 0,
    // and we do collision check of head with each part of body ,
    // but not head with head
    for (int i = 1; i < length; i++)
    {
        if ((getterOfHead()->getPosition().x < eachPart[i].getPosition().x + eachPart[i].getSize().x and eachPart[i].getPosition().x < getterOfHead()->getPosition().x + getSizeOfEachPart().x) and (getterOfHead()->getPosition().y < eachPart[i].getPosition().y + eachPart[i].getSize().y and eachPart[i].getPosition().y < getterOfHead()->getPosition().y + getSizeOfEachPart().y))
        {
            // code here means collision between snake head and a part of body.
            lives = 0;
            return true;
        }
    }
    return false;
}