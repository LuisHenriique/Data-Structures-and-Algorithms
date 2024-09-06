all: main.o item.o Deque.o
	gcc main.o item.o Deque.o -o main -std=c99 -Wall

main: 
	gcc -c main.c

item.o:
	gcc -c item.c

Deque.o:
	gcc -c Deque.c

run:all	
	./main

clean:

rm -rf *.o main