CC = gcc

main: main.o one-time.o
	$(CC) main.o one-time.o -o output.out

one-time.o: one-time.c
	$(CC) -c one-time.c -o one-time.o

main.o: main.c
	$(CC) -c main.c -o main.o
