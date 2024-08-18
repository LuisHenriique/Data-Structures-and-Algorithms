#ifndef CIRCULO_H
#define CIRCULO_H
#include "ponto.h"
#include <stdbool.h>

typedef struct circulo CIRCULO;

CIRCULO *circulo_criar(PONTO *p, float raio);
bool circulo_set_ponto(CIRCULO *c, PONTO *p);
bool circulo_set_raio(CIRCULO *c, float raio);
PONTO *circulo_get_ponto(CIRCULO *c);
float circulo_get_raio(CIRCULO *c);
void circulo_apagar(CIRCULO **circulo);

#endif