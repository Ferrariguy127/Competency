CC=gcc
CFLAGS=-g -Wall -std=c99
DEPS=matrix.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
main: main.o matrix.o
	$(CC) -o main main.o matrix.o
