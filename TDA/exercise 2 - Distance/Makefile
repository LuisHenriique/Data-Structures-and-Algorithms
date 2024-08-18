all: main.o ponto.o circulo.o
	gcc main.o ponto.o circulo.o -o main -std=c99 -Wall

main.o:
	gcc -c main.c

ponto.o:
	gcc -c ponto.c

circulo.o:
	gcc -c circulo.c

run: all
	./main

clean:
	rm -rf *.o main