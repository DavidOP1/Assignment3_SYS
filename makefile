CC=gcc
OBJECTS_MAIN=main.o
FLAGS= -Wall -g

all: stringProg Assignment3.o main.o
stringProg :Assignment3.o main.o
	$(CC) $(FLAGS)   -o stringProg $(OBJECTS_MAIN) Assignment3.o
Assignment3.o: Assignment3.c Assignment3.h
	$(CC) $(FLAGS) -c Assignment3.c Assignment3.h
main.o: main.c Assignment3.h 
	$(CC) $(FLAGS) -c main.c 
.PHONY: clean all
clean:
	rm -f *.o *.a *.so *.h.gch stringProg