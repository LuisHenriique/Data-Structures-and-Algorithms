#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "item.h"
#include "Pilha.h"
int main()
{
  // criar pilha
  PILHA *pilha;
  ITEM *item;
  pilha = pilha_criar();

  // n casos testes
  int n;
  scanf("%d", &n);

  // coleta dos casos testes
  int i = 0;
  while (i < n)
  {
    char stringInput[1000];
    scanf(" %s", stringInput);
    if (balanceada(stringInput))
    {
      printf("BALANCEADA");
    }
    else
    {
      printf("NÃO BALANCEADA");
    }

    i++;
  }
  return 0;
}
