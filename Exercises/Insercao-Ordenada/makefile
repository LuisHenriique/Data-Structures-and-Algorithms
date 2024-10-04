all: item.o lista.o main.o
	gcc item.o lista.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

lista.o:
	gcc -c lista.c

main.o:
	gcc -c main.c

run:all

	./main

clean:

	rm -rf *.o main