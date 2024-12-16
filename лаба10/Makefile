CC = gcc

all: cone_program

cone_program: main.o cone_functions.o
	$(CC) main.o cone_functions.o -o cone_program

main.o: main.c cone.h
	$(CC) -c main.c

cone_functions.o: cone_functions.c cone.h
	$(CC) -c cone_functions.c

clean:
	rm -f *.o cone_program