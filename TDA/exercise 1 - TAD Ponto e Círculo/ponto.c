#include "ponto.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ponto
{
  float x, y;
};

PONTO *ponto_criar(float x, float y)
{
  PONTO *p;
  p = (PONTO *)malloc(sizeof(PONTO));
  if (p == NULL)
  {
    exit(1);
  }

  p->x = x;
  p->y = y;

  return p;
}

void ponto_apagar(PONTO **p)
{
  if (p != NULL && *p != NULL)
    free(*p);
  *p = NULL;
}

bool ponto_set(PONTO *p, float x, float y)
{
  if (p != NULL)
  {
    p->x = x;
    p->y = y;
    return (true);
  }
  return (false);
}

float ponto_get_x(PONTO *p)
{
  if (p != NULL)
  {
    return (p->x);
  }
  return -1;
}
float ponto_get_y(PONTO *p)
{
  if (p != NULL)
  {
    return (p->y);
  }

  return -1;
}

void ponto_print(PONTO *p)
{
  printf("(%.1f, %.1f)", p->x, p->y);
}