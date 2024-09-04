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
    while ((*pilha)->top != NULL && !(pilha_vazia(pilha)))
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
  ITEM *item, *itemFinalResult;
  pilha = pilha_criar;

  // loop que vai até o final da string
  for (i = 0; (caracter_atual = sequencia[i]) != '\0'; i++)
  {
    if (caracter_atual != '+' && caracter_atual != '-' && caracter_atual != '*' && caracter_atual != '/')
    {

      // empilhamos todos os operandos excetos os operadores
      char *copy = (char *)malloc(sizeof(char)); // criado para evitar que caracter_atual sempre aponte para o último caracter lido da string
      copy = caracter_atual;
      item = item_criar(i, copy);
      pilha_empilhar(pilha, item);
    }
    if (caracter_atual == '+' || caracter_atual == '-' || caracter_atual == '*' || caracter_atual == '/')
    {

      // desempilha os operandos
      ITEM *opA = pilha_desempilhar(pilha);
      ITEM *opB = pilha_desempilhar(pilha);
      ITEM *result_operacao;

      char *operandoA = item_get_dados(opA);
      char *operandoB = item_get_dados(opB);

      // operação utilizando a tabela ASCII devido que estamos trabalhos com carateres da string, subtraindo por '0' obtemos os valores númericos na tabela ASCII, como as vez mandamos um float, não é necessário o cálculo
      float numberA, numberB;
      if (*operandoA == sizeof(char) || *operandoB == sizeof(char))
      {
        numberA = *operandoA - '0';
        numberB = *operandoB - '0';
      }
      else
      {
        numberA = *operandoA;
        numberB = *operandoB;
      }
      float result;

      // realiza as operações e empilha novamente, de acordo com a operação
      if (caracter_atual == '+')
      {
        result = numberA + numberB;
        result_operacao = item_criar(i, &result);
        pilha_empilhar(pilha, result_operacao);
      }
      if (caracter_atual == '-')
      {
        result = numberA - numberB;
        result_operacao = item_criar(i, &result);
        pilha_empilhar(pilha, result_operacao);
      }
      if (caracter_atual == '/')
      {
        result = numberA / numberB;
        result_operacao = item_criar(i, &result);
        pilha_empilhar(pilha, result_operacao);
      }
      if (caracter_atual == '*')
      {
        result = numberA * numberB;
        result_operacao = item_criar(i, &result);
        pilha_empilhar(pilha, result_operacao);
      }
    }
  }

  itemFinalResult = pilha_desempilhar(pilha);
  float *resultFinal = item_get_dados(itemFinalResult);
  pilha_apagar(&pilha);
  return (*resultFinal);
}