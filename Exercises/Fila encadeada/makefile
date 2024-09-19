all: main

main: main.o item.o fila.o
	gcc main.o item.o fila.o -o main -std=c99 -Wall

main.o: main.c
	gcc -c main.c

item.o: item.c
	gcc -c item.c

fila.o: fila.c
	gcc -c fila.c

run: all
	./main

clean:
	rm -rf *.o main

valgrind: all
	valgrind --leak-check=yes ./main