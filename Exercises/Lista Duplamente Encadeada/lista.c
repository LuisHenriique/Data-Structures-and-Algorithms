#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "item.h"
#include "lista.h"

typedef struct no_
{
  struct no_ *next;
  struct no_ *previous;
  ITEM *item;
} NOobj;

typedef NOobj NO;

struct lista_
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
bool lista_inserir_nao_ordenado(LISTA *lista, ITEM *item)
{
  if (lista != NULL && !lista_cheia(lista))
  {
    NO *new = (NO *)malloc(sizeof(NO));

    if (new == NULL)
      exit(1);

    new->item = item;
    new->next = NULL;
    new->previous = NULL;

    if (lista->length == 0)
    {
      lista->begin = new;
    }
    else
    {
      lista->end->next = new;
      new->previous = lista->end;
    }
    lista->length++;
    lista->end = new;
    return true;
  }
  return false;
}
bool lista_inserir_ordenado(LISTA *lista, ITEM *item, int chave)
{

  if (lista != NULL && !lista_cheia(lista))
  {
    NO *new = (NO *)malloc(sizeof(NO));
    NO *p = NULL;

    if (new == NULL)
      exit(1);

    new->item = item;
    new->next = NULL;
    new->previous = NULL;

    // caso a lista esteja vazia
    if (lista->length == 0)
    {
      lista->begin = new;
      lista->end = new;
      lista->length++;
      return true;
    }
    p = lista->begin;
    while (p != NULL && item_get_chave(p->item) < chave)
    {
      if (p->next == NULL)
        break;

      p = p->next;
    }

    if (p == lista->begin && lista->length > 1) // Insere no início
    {
      lista->begin = new;
      p->previous = new;
      new->next = p;
    }

    else if (p->next == NULL && p == lista->end) // Insere no fim
    {
      p->next = new;
      new->previous = p;
      lista->end = new;
    }
    else // insere no meio
    {
      p->previous->next = new;
      new->previous = p->previous;
      p->previous = new;
      new->next = p;
    }

    lista->length++;
    return true;
  }
  return false;
}

bool lista_inserir(LISTA *lista, ITEM *item)
{
  if (lista != NULL)
  {
    if (lista->ordenada)
    {
      int x = item_get_chave(item);
      return lista_inserir_ordenado(lista, item, x);
    }
    else
    {
      return lista_inserir_nao_ordenado(lista, item);
    }
  }
}
ITEM *lista_remover(LISTA *lista, int chave)
{
  if (lista != NULL && !(lista_vazia(lista)))
  { // Fazer um sistema de busca
    NO *p = NULL;
    ITEM *it;

    p = lista->begin;
    while (p != NULL && item_get_chave(p->item) != chave)
    {
      p = p->next;
    }

    it = p->item;

    if (p != NULL)
    {
      // Remove no início
      if (p == lista->begin)
      {
        lista->begin = p->next;
        lista->begin->previous = NULL;
      }
      else if (p->next != NULL) // remove no meio
      {
        p->previous->next = p->next;
        p->next->previous = p->previous;
      }
      else // remove no fim
      {
        p->previous->next = p->next;
        lista->end = p->previous;
      }

      p->next = NULL;
      p->previous = NULL;
      free(p);
      p = NULL;
      lista->length--;
    }

    return it;
  }

  return NULL;
}
int lista_tamanho(LISTA *lista)
{
  if (lista != NULL)
  {
    return lista->length;
  }
  return -1;
}
bool lista_vazia(LISTA *lista)
{
  if (lista != NULL)
  {
    return (lista->length == 0) ? true : false;
  }
}
bool lista_cheia(LISTA *lista)
{
  if (lista != NULL)
  {
    NO *new = (NO *)malloc(sizeof(NO));
    if (new != NULL)
    {
      free(new);
      new = NULL;
      return false;
    }
    return false;
  }
  return true;
}
bool lista_apagar(LISTA **lista)
{
  if (lista != NULL && *lista != NULL)
  {
    NO *p = NULL;
    p = (*lista)->begin;
    while (p != NULL && p->next != NULL)
    {
      p = p->next;
      item_apagar(&p->previous->item);
      p->previous->next = NULL;
      free(p->previous);
      p->previous = NULL;
    }

    if (p != NULL)
    {
      item_apagar(&p->item);
      free(p);
      p = NULL;
    }
    free(*lista);
    *lista = NULL;
    return true;
  }
  return false;
}
ITEM *lista_busca(LISTA *lista, int chave)
{
  if (lista != NULL && !(lista_vazia(lista)))
  {
    NO *p = NULL;
    p = lista->begin;
    while (p != NULL)
    {
      if (item_get_chave(p->item) == chave)
        return p->item;

      p = p->next;
    }
  }
  return NULL;
}
void lista_imprimir(LISTA *lista)
{
  if (lista != NULL && !(lista_vazia(lista)))
  {
    NO *p = NULL;
    p = lista->begin;
    while (p != NULL)
    {
      printf(" [%d] ", item_get_chave(p->item));

      p = p->next;
    }
  }
}