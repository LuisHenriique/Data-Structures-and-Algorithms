#include "circulo.h"
#include "ponto.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct circulo
{
  float raio;
  PONTO *p;
};

CIRCULO *circulo_criar(PONTO *p, float raio)
{
  CIRCULO *c = (CIRCULO *)malloc(sizeof(CIRCULO));
  if (c == NULL)
    exit(1);

  c->p = p;
  c->raio = raio;

  return c;
}

bool circulo_set_ponto(CIRCULO *c, PONTO *p)
{
  if (c != NULL)
  {
    c->p = p;

    return (true);
  }
  return (false);
}
bool circulo_set_raio(CIRCULO *c, float raio)
{
  if (c != NULL)
  {
    c->raio = raio;
    return true;
  }

  return false;
}
PONTO *circulo_get_ponto(CIRCULO *c)
{
  if (c != NULL)
  {
    return c->p;
  }

  return NULL;
}
float circulo_get_raio(CIRCULO *c)
{
  if (c != NULL)
  {
    return (c->raio);
  }

  return -1;
}

void circulo_apagar(CIRCULO **circulo)
{
  if (*circulo != NULL && circulo != NULL)
    free(*circulo);
  *circulo = NULL;
}