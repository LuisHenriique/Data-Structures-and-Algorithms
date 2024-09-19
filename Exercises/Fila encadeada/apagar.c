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

void fila_apagar(FILA **fila)
{

  // caso base a função recusiva vai até aqui
  if (fila_vazia((*fila)))
  {
    free(*fila);
    *fila = NULL;
  }
  // Instâncias
  else
  {
    item_apagar(&(*fila)->inicio->item);
    free(fila_remover(*fila));

    // Dando um free diretamente no item retornado, pois cada item foi alocado dinamicamente ao ter a chamada do item_criar()
    fila_apagar(fila);
  }
}