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