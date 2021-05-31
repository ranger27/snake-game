CC=g++
EXEC=snake
FLAGS= -lsfml-graphics -lsfml-window -lsfml-system

$(EXEC: main.o
	$(CC) main.o -o $(EXEC) $(FLAGS)

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o $(EXEC)