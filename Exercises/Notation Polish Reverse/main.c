#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "Pilha.h"

int main()
{
  char str[100];
  PILHA *p;
  p = pilha_criar();

  int n;
  int i = 0;
  printf("Qtda:\n");
  scanf("%d", &n);
  while (i < n)
  {
    scanf(" %s", str);
    float result = rpn(str);
    printf("\nresult: %.2f\n", result);
    i++;
  }

  pilha_apagar(&p);
  return 0;
}
