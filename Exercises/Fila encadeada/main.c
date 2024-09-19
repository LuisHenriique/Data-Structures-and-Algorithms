#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "fila.h"

int main()
{
  int number;
  int aux;
  FILA *queue = fila_criar();
  ITEM *item;
  scanf("%d", &number);
  int i = 0;
  while (i < number)
  {
    scanf("%d", &aux);
    item = item_criar(i, &aux);
    fila_inserir(queue, item);
    i++;
  }
  printf("\nTam inicial: %d\n", fila_tamanho(queue));

  ITEM *test = fila_remover(queue);
  int *itemFim = item_get_dados(test);
  printf("\nInício da fila, 1º element : %d ", *itemFim);

  ITEM *test2 = fila_remover(queue);
  int *itemFim2 = item_get_dados(test2);
  printf("\nInício da fila, 2º element : %d ", *itemFim2);

  printf("\nTam inicial: %d\n", fila_tamanho(queue));

  fila_apagar(&queue);

  return 0;
}
