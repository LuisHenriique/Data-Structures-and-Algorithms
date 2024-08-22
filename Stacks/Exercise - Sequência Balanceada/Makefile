all: balanceada.o item.o Pilha.o
		gcc balanceada.o item.o Pilha.o -o balanceada -std=c99 -Wall

balanceada.o:
	gcc -c balanceada.c

item.o:

	gcc -c item.c

Pilha.o: 
	gcc -c Pilha.c

run: all
	./balanceada

clean:

	rm -rf *.o balanceada

	