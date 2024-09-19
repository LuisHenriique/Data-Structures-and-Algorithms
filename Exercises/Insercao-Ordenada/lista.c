#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "lista.h"

#ifndef STRUCTS_

#define STRUCTS_

struct lista_
{

  ITEM *list[TAM_MAX];

  int beginning; // pos do primeiro item

  int end; // pos do próximo espaço vazio

  int length;
};

#endif

LISTA *lista_criar()
{
  LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
  if (lista != NULL)
  {
    lista->beginning = 0;
    lista->end = 0;
    lista->length = 0;

    return lista;
  }

  return NULL;
}
int lista_busca_ordenada(LISTA *lista, int chave)
{
  int i;
  int inf = lista->beginning;
  int sup = lista->end;
  int middle = (inf + sup) / 2;
}
bool lista_inserir(LISTA *lista, ITEM *item)
{
  // binary search
  int x = lista_busca_ordenada(lista, item_get_chave(item));

  if (lista_vazia(lista))
  {
    lista->list[lista->end] = item;
    lista->end++;
  }
  else
  {
  }
  lista->length++;
}
void lista_apagar(LISTA **lista)
{
}

int lista_tamanho(LISTA *lista)
{
}
bool lista_vazia(LISTA *lista)
{
}
bool lista_cheia(LISTA *lista)
{
}
void lista_imprimir(LISTA *lista)
{
}
