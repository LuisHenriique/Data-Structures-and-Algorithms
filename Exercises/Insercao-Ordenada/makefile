all: item.o lista.o main.o
	gcc item.o lista.o main.o -o main -std=c99 -Wall

main.o:
	gcc -c main.c

lista.o:
	gcc -c lista.c

item.o:
	gcc -c item.c

run:all

	./main

clean:

	rm -rf *.o main