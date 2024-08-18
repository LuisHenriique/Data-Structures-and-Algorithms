#include "ponto.h"
#include "circulo.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
  // variáveis para coletar os dados dos usuários
  float x, y, x1, y1;
  float raio;
  // coleta os dados
  scanf(" %f %f %f %f %f", &x, &y, &x1, &y1, &raio);

  // chamada de função para criar pontos
  PONTO *p1 = ponto_criar(x, y);
  PONTO *p2_centro = ponto_criar(x1, y1);

  // cria uma circulo
  CIRCULO *c1 = circulo_criar(p2_centro, raio);

  // Coleta dados do circulo(raio)
  float coletaRaio = circulo_get_raio(c1);

  // imprime
  printf("Ponto: ");
  ponto_print(p1);
  printf("\nCirculo: Centro ");
  ponto_print(p2_centro);
  printf(", Raio = %.1f\n", coletaRaio);

  // libera memória
  ponto_apagar(&p1);
  ponto_apagar(&p2_centro);
  circulo_apagar(&c1);
  return 0;
}