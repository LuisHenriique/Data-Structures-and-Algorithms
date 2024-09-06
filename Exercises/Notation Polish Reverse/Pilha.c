#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "item.h"
typedef struct no NO;

struct pilha
{
  NO *top;
  int length;
};

struct no
{
  NO *previous;
  ITEM *it;
};

PILHA *pilha_criar(void)
{

  PILHA *p = (PILHA *)malloc(sizeof(PILHA));

  if (p != NULL)
  {
    p->top = NULL;
    p->length = 0;

    return p;
  }
}

void pilha_apagar(PILHA **pilha)
{
  NO *auxp;
  if (pilha != NULL)
  {
    while ((*pilha)->top != NULL && !(pilha_vazia((*pilha))))
    {
      auxp = (*pilha)->top;
      (*pilha)->top = (*pilha)->top->previous;
      item_apagar(&auxp->it);
      auxp->previous = NULL;
      free(auxp);
      auxp = NULL;
      (*pilha)->length--;
    }
  }

  free(*pilha);
  (*pilha) = NULL;
}
bool pilha_vazia(PILHA *pilha)
{
  if (pilha != NULL)
    return (pilha->length == 0) ? true : false;
}
bool pilha_cheia(PILHA *pilha)
{
  if (pilha != NULL)
  {
    NO *new = (NO *)malloc(sizeof(NO));
    if (new != NULL)
    {
      free(new);
      return false;
    }
  }

  return true;
}
int pilha_tamanho(PILHA *pilha)
{
  if (pilha != NULL)
    return (pilha->length);
}
ITEM *pilha_topo(PILHA *pilha)
{
  if (!(pilha_vazia(pilha)) && pilha != NULL)
  {

    return pilha->top->it;
  }
}

bool pilha_empilhar(PILHA *pilha, ITEM *item)
{
  if (!pilha_cheia(pilha) && pilha != NULL)
  {

    NO *new = (NO *)malloc(sizeof(NO));
    new->it = item;
    new->previous = pilha->top;
    pilha->top = new;
    pilha->length++;
    return true;
  }

  return false;
}
ITEM *pilha_desempilhar(PILHA *pilha)
{
  if (!(pilha_vazia(pilha)) && (pilha != NULL))
  {
    NO *store_TOP;
    ITEM *aux;
    aux = pilha->top->it;
    store_TOP = pilha->top;
    pilha->top = pilha->top->previous;

    store_TOP->it = NULL;
    store_TOP->previous = NULL;
    free(store_TOP);
    store_TOP = NULL;

    pilha->length--;

    return aux;
  }
}

float rpn(char *sequencia)
{
  // variáveis e declaração
  int i;
  char caracter_atual;
  PILHA *pilha;
  pilha = pilha_criar();

  // loop que vai até o final da string
  for (i = 0; (caracter_atual = sequencia[i]) != '\0'; i++)
  {
    if (caracter_atual != '+' && caracter_atual != '-' && caracter_atual != '*' && caracter_atual != '/')
    {
      float *copy = (float *)malloc(sizeof(float)); // criado para evitar que caracter_atual sempre aponte para o último caracter lido da string
      *copy = (caracter_atual - '0');               // Converte o caractere para número com base na tabela ASCII
      ITEM *item = item_criar(i, copy);
      pilha_empilhar(pilha, item); // empilhamos todos os operandos excetos os operadores
    }
    else
    {

      // desempilha os operandos
      ITEM *opA = pilha_desempilhar(pilha);
      ITEM *opB = pilha_desempilhar(pilha);

      float *operandoA = item_get_dados(opA);
      float *operandoB = item_get_dados(opB);

      float numberA, numberB;

      numberA = *operandoA;
      numberB = *operandoB;

      float result;
      // realiza as operações e empilha novamente, de acordo com a operação
      switch (caracter_atual)
      {
      case '+':
        result = numberB + numberA;

        break;
      case '-':
        result = numberB - numberA;

        break;

      case '*':
        result = numberB * numberA;

        break;

      case '/':
        result = numberB / numberA;
        break;
      }

      float *resultAllocation = (float *)malloc(sizeof(float));

      if (resultAllocation == NULL)
      {
        exit(1);
      }
      *resultAllocation = result;
      ITEM *result_operacao = item_criar(i, resultAllocation);

      pilha_empilhar(pilha, result_operacao);
      free(operandoA);
      free(operandoB);
      item_apagar(&opA);
      item_apagar(&opB);
    }
  }

  ITEM *itemFinalResult = NULL;
  itemFinalResult = pilha_desempilhar(pilha);
  float *resultFinal = item_get_dados(itemFinalResult);
  float resultado = *resultFinal;

  pilha_apagar(&pilha);
  free(resultFinal);
  item_apagar(&itemFinalResult);

  return resultado;
}