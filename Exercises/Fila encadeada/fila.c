#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "fila.h"

#ifndef _STRUCTS_

#define _STRUCTS_

typedef struct no_
{

  ITEM *item;

  struct no_ *proximo;

} noObj;

typedef noObj NO;

typedef struct fila_
{

  NO *inicio;

  NO *fim;

  int tamanho;

} filaObj;

typedef filaObj FILA;

#endif

FILA *
fila_criar(void)
{
  FILA *fila = (FILA *)malloc(sizeof(FILA));
  if (fila != NULL)
  {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;

    return fila;
  }
  return NULL;
}
bool fila_inserir(FILA *fila, ITEM *item)
{
  if (fila != NULL && !fila_cheia(fila))
  {
    NO *new = (NO *)malloc(sizeof(NO));
    if (new == NULL)
      exit(1);

    new->item = item;

    if (fila->tamanho == 0)
    {
      fila->inicio = new;
      fila->fim = new;
    }
    else
    {

      fila->fim->proximo = new;
      fila->fim = new;
    }

    fila->tamanho++;
    new->proximo = NULL;

    return true;
  }
  return false;
}
ITEM *fila_remover(FILA *fila)
{
  if (fila != NULL && !(fila_vazia(fila)))
  {
    ITEM *it;
    NO *aux;
    // variáveis auxiliares que guardam endereços
    it = fila->inicio->item;
    aux = fila->inicio;

    fila->tamanho--;
    fila->inicio->item = NULL;
    fila->inicio = aux->proximo;

    if (fila->tamanho == 0)
    {
      fila->fim = NULL;
    }

    free(aux);
    aux = NULL;

    return it;
  }
  return NULL;
}
void fila_apagar(FILA **fila)
{

  // caso base a função recusiva vai até aqui
  if (fila_vazia((*fila)))
  {
    free(*fila);
    *fila = NULL;
    printf("Fila vazia!\n");
  }
  // Instâncias
  else
  {
    free(fila_remover(*fila));
    fila_apagar(fila);
  }
}
ITEM *fila_frente(FILA *fila)
{
  return (fila != NULL && !(fila_vazia(fila))) ? fila->inicio->item : NULL;
}

int fila_tamanho(FILA *fila)
{
  return (fila != NULL) ? fila->tamanho : -1;
}
bool fila_vazia(FILA *fila)
{
  if (fila != NULL)
  {
    if (fila->tamanho == 0)
      return true;

    return false;
  }
}
bool fila_cheia(FILA *fila)
{
  NO *new;
  new = (NO *)malloc(sizeof(NO));
  if (fila != NULL)
  {
    if (new != NULL)
    {
      free(new);
      new = NULL;
      return false;
    }
  }
  return true;
}
