#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "lista.h"

int main()
{
  int n, number;
  int i = 0;
  scanf("%d", &n);

  LISTA *lista;
  lista = lista_criar();
  ITEM *item;

  while (i < n)
  {
    scanf("%d", &number);
    item = item_criar(number, NULL);
    bool ok = lista_inserir(lista, item);
    if (ok)
      printf("Coletado: %d\n", number);

    i++;
  }
  lista_inserir(lista, item_criar(14, NULL));

  printf("Tamanho: %d\n", lista_tamanho(lista));
  lista_imprimir(lista);
  return 0;
}