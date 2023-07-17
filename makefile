CC=g++
CFLAGS=-g -Wall

all: add_nbo

add_nbo: add_nbo.o
	$(CC) $(CFLAGS) -o add_nbo add_nbo.o

add_nbo.o: add_nbo.cpp
	$(CC) $(CFLAGS) -c add_nbo.cpp

clean:
	rm -f add_nbo *.o

