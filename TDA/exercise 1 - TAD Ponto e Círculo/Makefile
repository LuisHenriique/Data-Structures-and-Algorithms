all: main.o circulo.o ponto.o
	gcc main.o circulo.o ponto.o -o main -std=c99 -Wall

main.o: 
	gcc -c main.c
	
circulo.o: 
	gcc -c circulo.c
	
ponto.o:
	gcc -c ponto.c
	
run: all
	./main

clean:
	rm -rf *.o main
