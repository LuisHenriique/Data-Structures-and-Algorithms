#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "lista.h"

#ifndef STRUCTS_

#define STRUCTS_

struct lista_
{

  ITEM *lista[TAM_MAX];

  int inicio; // pos do primeiro item

  int fim; // pos do próximo espaço vazio

  int tamanho;
};

#endif

int lista_busca_ordenada(LISTA *lista, int chave)
{
  int inf = lista->inicio;
  int sup = lista->fim - 1; // fim é o próximo espaço vazio, então fim - 1 é o último item válido.
  int middle;

  if (lista != NULL && !lista_vazia(lista))
  {
    while (inf <= sup)
    {
      middle = (inf + sup) / 2;

      if (item_get_chave(lista->lista[middle]) == chave)
        return middle; // encontrou o item

      if (item_get_chave(lista->lista[middle]) > chave)
        sup = middle - 1;
      else
        inf = middle + 1;
    }
  }

  // Retorna 'inf', que será o local apropriado para inserção
  return inf;
}

bool lista_inserir(LISTA *lista, ITEM *item)
{
  if (lista != NULL)
  {

    if (lista_vazia(lista))
    {
      lista->lista[lista->fim] = item;
      lista->tamanho++;
      lista->fim++;
      return true;
    }

    int i;
    int x = lista_busca_ordenada(lista, item_get_chave(item)); // busca o local de inserção

    if (!lista_cheia(lista)) // verifica se a lista não está cheia
    {
      for (i = lista->fim; i > x; i--) // desloca os elementos para a direita
      {
        lista->lista[i] = lista->lista[i - 1];
      }

      lista->lista[x] = item; // insere o novo item
      lista->tamanho++;
      lista->fim++;
      return true;
    }
  }

  return false;
}