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
    if (new == NULL)
      exit(1);

    new->item = item;

    if (lista->length == 0)
      lista->begin = new;
    else
    {
      lista->end->next = new;
    }
    lista->end = new;
    new->next = NULL;
    lista->length++;
    return true;
  }
  return false;
}
bool lista_inserir_ordenada(LISTA *lista, ITEM *item, int chave)
{
  if (lista != NULL && !lista_cheia(lista))
  {
    NO *new = (NO *)malloc(sizeof(NO));
    NO *p = NULL;
    NO *aux = NULL;

    if (new == NULL)
    {
      exit(1);
    }

    new->item = item;
    new->next = NULL;

    // Inserção para caso a lista estiver vazia
    if (lista->length == 0)
    {
      lista->begin = new;
      lista->end = new;
      lista->length++;
      return true;
    }

    // Sistema de busca da inserção ordenada
    p = lista->begin;

    while (p != NULL && item_get_chave(p->item) < chave)
    {
      aux = p;
      p = p->next;
    }

    // Caso de quando a inserção é no início
    if (p == lista->begin)
    {
      lista->begin = new;
      new->next = p;
    }
    else
    {
      aux->next = new;
      new->next = p;

      if (p == NULL)
        lista->end = new;
    }

    lista->length++;
    return true;
  }
  return false;
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
  if (lista != NULL && !lista_vazia(lista))
  {
    NO *aux = NULL;
    NO *p = NULL;
    ITEM *it;
    p = lista->begin;

    while (p != NULL && item_get_chave(p->item) != chave)
    {
      aux = p;
      p = p->next;
    }

    if (p != NULL)
    {

      if (p == lista->begin)
      {
        lista->begin = p->next;
      }
      else
      {
        aux->next = p->next;
      }
      p->next = NULL;

      if (p == lista->end) // ajustando o ponteiro fim
        lista->end = aux;

      it = p->item; // guarda o conteúdo do nó que será removido
      lista->length--;
      free(p);
      p = NULL;
      return it;
    }
  }

  return NULL;
}

bool lista_apagar(LISTA **lista)
{
  if (lista != NULL)
  {
    NO *p, *aux;

    p = (*lista)->begin;
    while (p != NULL)
    {
      aux = p;
      p = p->next;
      item_apagar(&aux->item);
      aux->next = NULL;
      free(aux);
      aux = NULL;
    }

    free(*lista);
    (*lista) = NULL;

    return true;
  }

  return false;
}
ITEM *lista_busca(LISTA *lista, int chave)
{
  if (lista != NULL && !lista_vazia(lista))
  {

    NO *p = lista->begin;

    while (p != NULL)
    {
      if (item_get_chave(p->item) > chave && lista->ordenada)
        return NULL;

      if (item_get_chave(p->item) == chave) // Sistema de busca que roda toda a lista --- O(n)
        return p->item;

      p = p->next;
    }
  }

  return NULL;
}
int lista_tamanho(LISTA *lista)
{
  return (lista != NULL) ? lista->length : -1;
}
bool lista_vazia(LISTA *lista)
{
  return lista != NULL && lista->length == 0;
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
    return true;
  }
}
void lista_imprimir(LISTA *lista)
{
  if (lista != NULL && !lista_vazia(lista))
  {
    NO *p;
    p = lista->begin;

    while (p != NULL)
    {
      printf(" [%d] ", item_get_chave(p->item));
      p = p->next;
    }
  }
}

/*Funcoes adicionais*/
int lista_inverter(LISTA **lista) {}
bool lista_comparar(LISTA *l1, LISTA *l2) {}
