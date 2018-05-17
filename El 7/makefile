CC = g++
CFLAGS = -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

main: chess.o io.o main.o
	$(CC) $(FLAGS) -o Tarea3 chess.o io.o main.o

main.o: main.cpp
	$(CC) $(FLAGS) -c -o main.o main.cpp

chess.o: chess.cpp
	$(CC) $(FLAGS) -c -o chess.o chess.cpp

io.o: io.cpp
	$(CC) $(FLAGS) -c -o io.o io.cpp

clean:
	rm *.o
	rm Tarea3

