all: item.o Pilha.o main.o
	gcc item.o Pilha.o main.o -o main -std=c99 -Wall
main.o: 
	gcc -c main.o

item.o:
	gcc -c item.c

Pilha.o: 
	gcc -c Pilha.c

run: all
	./main

clean:
	rm -rf *.o main
