#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "item.h"

typedef struct no_
{
  struct no_ *next;
  ITEM *item;
} NOobj;

typedef NOobj NO;

struct lista
{
  NO *begin;
  NO *end;
  int length;
  bool ordenada;
};

LISTA *lista_criar(bool ordenada)
{
  LISTA *lista = (LISTA *)malloc(sizeof(LISTA));

  if (lista != NULL)
  {
    lista->begin = NULL;
    lista->end = NULL;
    lista->length = 0;
    lista->ordenada = ordenada;

    return lista;
  }

  return NULL;
}
bool lista_inserir_nao_ordenada(LISTA *lista, ITEM *item)
{
  if (lista != NULL && !lista_cheia(lista))
  {
    NO *new = (NO *)malloc(sizeof(NO));
    NO *aux;
    aux = new;
    if (new == NULL)
      exit(1);

    aux->item = item;

    if (lista->length == 0)
    {
      lista->begin = aux;
      lista->end = aux;
    }
    else
    {
      lista->end->next = aux;
      lista->end = aux;
    }
    aux->next = NULL;
    lista->length++;
    return true;
  }
  return false;
}
bool lista_inserir_ordenada(LISTA *lista, ITEM *item, int chave)
{
  if (lista != NULL && !lista_cheia(lista))
  {

    lista->length++;
  }
}
bool lista_inserir(LISTA *lista, ITEM *item)
{

  if (lista->ordenada)
  {
    int x = item_get_chave(item);
    return lista_inserir_ordenada(lista, item, x);
  }
  else
  {
    return lista_inserir_nao_ordenada(lista, item);
  }
}
ITEM *lista_remover(LISTA *lista, int chave)
{
}

//--------------------------------------------------------- Later
bool lista_apagar(LISTA **lista) {}
ITEM *lista_busca(LISTA *lista, int chave) {}
int lista_tamanho(LISTA *lista) {}
bool lista_vazia(LISTA *lista) {}
bool lista_cheia(LISTA *lista) {}
void lista_imprimir(LISTA *lista) {}

/*Fun��es adicionais*/
int lista_inverter(LISTA **lista) {}
bool lista_comparar(LISTA *l1, LISTA *l2) {}
