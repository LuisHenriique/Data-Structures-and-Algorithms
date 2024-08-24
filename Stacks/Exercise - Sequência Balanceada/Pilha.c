#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Pilha.h"
#include "item.h"

struct pilha
{
  int length; // Topo da pilha
  ITEM *item[TAM];
};
PILHA *pilha_criar(void)
{
  PILHA *pilha;
  pilha = (PILHA *)malloc(sizeof(PILHA));
  if (pilha != NULL)
  {
    pilha->length = 0;
    return pilha;
  }

  return NULL;
}

void pilha_apagar(PILHA **pilha)
{
  if (*pilha != NULL && pilha != NULL)
  {
    free(*pilha);
    *pilha = NULL;
  }
}

bool pilha_vazia(PILHA *pilha)
{
  if (pilha != NULL)
  {
    return (pilha->length == 0) ? true : false;
  }
}

bool pilha_cheia(PILHA *pilha)
{
  if (pilha != NULL)
  {
    return (pilha->length == TAM) ? true : false;
  }
}

int pilha_tamanho(PILHA *pilha)
{
  return (pilha != NULL) ? pilha->length : -1;
}

ITEM *pilha_topo(PILHA *pilha)
{
  return (pilha != NULL) ? pilha->item[pilha->length - 1] : NULL;
}

bool pilha_empilhar(PILHA *pilha, ITEM *item)
{
  if (pilha != NULL && !(pilha_cheia(pilha)))
  {
    pilha->item[pilha->length] = item;
    pilha->length++;
    return true;
  }

  return false;
}

ITEM *pilha_desempilhar(PILHA *pilha)
{

  ITEM *i;
  if (pilha != NULL && !(pilha_vazia(pilha)))
  {
    i = pilha_topo(pilha);
    pilha->item[pilha->length - 1] = NULL;
    pilha->length--;

    return i;
  }

  return NULL;
}

bool balanceada(char *sequencia)
{
  PILHA *pilha = pilha_criar();
  char caractereAtual;
  int i;
  for (i = 0; (caractereAtual = sequencia[i]) != '\0'; i++)
  {
    if (caractereAtual == '(' || caractereAtual == '{' || caractereAtual == '[')
    {
      ITEM *item = item_criar(i, &caractereAtual);
      pilha_empilhar(pilha, item);
    }
    if (caractereAtual == ')' || caractereAtual == '}' || caractereAtual == ']')
    {
      if (pilha_vazia(pilha))
      {
        pilha_apagar(&pilha);

        return false;
      }

      ITEM *top = pilha_topo(pilha);
      char *caracters = item_get_dados(top);

      if (caractereAtual == ']' && *caracters == '[' || caractereAtual == '}' && *caracters == '{' || caractereAtual == ')' && *caracters == '(')
      {
        pilha_desempilhar(pilha);
      }
      else
      {
        pilha_apagar(&pilha);
        return false;
      }
    }
  }
  bool result = pilha_vazia(pilha);
  pilha_apagar(&pilha);
  return result;
}