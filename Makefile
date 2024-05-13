CC=gcc
CFLAGS=-g -Wall -std=c99
DEPS=matrix.h

all: matrix.o main.o test.o main test


matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) matrix.c -c matrix.o

main.o: main.c
	$(CC) $(CFLAGS) main.c -c main.o

test.o: test.c
	$(CC) $(CFLAGS) test.c -c test.o

main: main.o matrix.o
	$(CC) -o main main.o matrix.o 

test: test.o matrix.o
	$(CC) test -o test.o matrix.o 

clean:
	rm main test main.o test.o matrix.o

run:
	./main

debug:
	./test