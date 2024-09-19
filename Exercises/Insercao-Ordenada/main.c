#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "lista.h"

int main()
{
  int n, number, i = 0;
  scanf("%d", &n);

  LISTA *lista;
  lista = lista_criar();
  ITEM *item;

  while (i < n)
  {
    scanf("%d", &number);
    item = item_criar(i, &number);
    lista_inserir(lista, item);
    i++;
  }

  return 0;
}