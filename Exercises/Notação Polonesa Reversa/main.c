#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "Pilha.h"

int main()
{
  char *str[100];
  PILHA *p;
  ITEM *it;
  p = pilha_criar();
  while (str != "sair")
  {
    scanf(" %s", str);
    float result = rpn(str);
    printf("%f", result);
  }

  pilha_apagar(&p);
  return 0;
}
