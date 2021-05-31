namespace snake
{
    class Snake
    {
        int length;
        enum Direction
        {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        Direction direction;

    public:
        Snake() {}
        Direction getDirection();
    };
};
