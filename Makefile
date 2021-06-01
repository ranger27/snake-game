CC=g++
EXEC=finalgame
GAME_FOLDER=./Game
SNAKE_FOLDER=./snake
FLAGS=-std=c++11 
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

$(EXEC): main.o game.o snake.o
	$(CC) main.o game.o snake.o $(FLAGS) $(SFML_FLAGS) -o $(EXEC) 

main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp

game.o: $(GAME_FOLDER)/game.cpp
	$(CC) $(FLAGS) -c $(GAME_FOLDER)/game.cpp

snake.o: $(SNAKE_FOLDER)/snake.cpp
	$(CC) $(FLAGS) -c $(SNAKE_FOLDER)/snake.cpp

clean:
	rm *.o $(EXEC)