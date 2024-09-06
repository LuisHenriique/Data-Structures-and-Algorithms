#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "Deque.h"

struct deque_
{
  ITEM *deque[MAX_TAMANHO];
  int length;
  int beginning;
  int end;
};

DEQUE *deque_criar()
{
  DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));
  if (deque != NULL)
  {
    deque->beginning = 0;
    deque->length = 0;
    deque->end = 0;

    return deque;
  }

  return NULL;
}
void deque_apagar(DEQUE **deque)
{
  if (*deque != NULL && deque != NULL)
  {

    for (int i = 0; i < MAX_TAMANHO; i++)
    {
      if ((*deque)->deque[i] != NULL)
        free((*deque)->deque[i]);
    }
    free(*deque);
    *deque = NULL;
  }
}

bool deque_inserir_inicio(DEQUE *deque, ITEM *item)
{
  if (deque != NULL && !(deque_cheia(deque)))
  {
    deque->beginning--;
    if (deque->beginning < 0)
      deque->beginning = MAX_TAMANHO - 1;

    deque->deque[deque->beginning] = item;
    deque->length++;

    return true;
  }
  return false;
}
bool deque_inserir_fim(DEQUE *deque, ITEM *item)
{
  if (deque != NULL && !(deque_cheia(deque)))
  {
    deque->deque[deque->end] = item;
    deque->end = (deque->end + 1) % MAX_TAMANHO;
    deque->length++;

    return true;
  }

  return false;
}

ITEM *deque_remover_inicio(DEQUE *deque)
{
  if (deque != NULL && !(deque_vazia(deque)))
  {
    ITEM *i = deque->deque[deque->beginning];
    deque->deque[deque->beginning] = NULL;
    deque->beginning = (deque->beginning + 1) % MAX_TAMANHO;
    deque->length--;
    return i;
  }
  return NULL;
}
ITEM *deque_remover_fim(DEQUE *deque)
{
  if (deque != NULL && !(deque_vazia(deque)))
  {
    deque->end = (deque->end - 1 + MAX_TAMANHO) % MAX_TAMANHO; // Atualiza o índice de forma circular
    ITEM *i = deque->deque[deque->end];
    deque->deque[deque->end] = NULL;
    deque->length--;
    return i;
  }
  return NULL;
}

ITEM *deque_primeiro(DEQUE *deque)
{
  if (deque != NULL && !(deque_vazia(deque)))
  {
    return deque->deque[deque->beginning];
  }
  return NULL;
}
ITEM *deque_ultimo(DEQUE *deque)
{
  if (deque != NULL && !(deque_vazia(deque)))
  {
    int last = (deque->end - 1 + MAX_TAMANHO) % MAX_TAMANHO;
    return deque->deque[last];
  }
  return NULL;
}

int deque_contar(DEQUE *deque)
{
  if (deque != NULL)
  {
    return deque->length;
  }
  return 0;
}
bool deque_vazia(DEQUE *deque)
{
  return deque == NULL || deque->length == 0;
}

bool deque_cheia(DEQUE *deque)
{

  return deque != NULL && deque->length == MAX_TAMANHO;
}
