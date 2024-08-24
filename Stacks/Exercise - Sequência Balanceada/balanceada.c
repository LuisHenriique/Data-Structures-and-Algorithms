#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "item.h"
#include "Pilha.h"

int main()
{
  // criar pilha
  PILHA *pilha;
  pilha = pilha_criar();

  // n casos testes
  int n;
  scanf("%d", &n);

  // coleta dos casos testes
  int i = 0;
  while (i < n)
  {
    bool result;
    char stringInput[1000];
    scanf(" %s", stringInput);
    result = (balanceada(stringInput));
    if (result)
    {
      printf("BALANCEADA\n");
    }
    else
    {
      printf("NÃO BALANCEADA\n");
    }

    i++;
  }
  pilha_apagar(&pilha);
  return 0;
}
