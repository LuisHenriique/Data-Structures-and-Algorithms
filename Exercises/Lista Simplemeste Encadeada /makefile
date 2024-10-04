all: main.o item.o lista.o
	gcc main.o item.o lista.o -o main -std=c99 -Wall
main.o: 
	gcc -c main.c

item.o:
	gcc -c item.c

lista.o: 
	gcc -c lista.c

run: all
	./main

clean:
	rm -rf *.o main
