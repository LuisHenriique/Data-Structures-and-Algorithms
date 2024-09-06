all: main.o item.o Pilha.o
	gcc main.o item.o Pilha.o -o main -std=c99 -Wall
main.o: 
	gcc -c main.c

item.o:
	gcc -c item.c

Pilha.o: 
	gcc -c Pilha.c

run: all
	./main

clean:
	rm -rf *.o main
