#include "snake.hpp";


namespace game{
    class Game{
        int score;
        int lives;
        snake::Snake player;
        public:
        Game(){
            score = 0;
            lives = 1;
        }
    };
}