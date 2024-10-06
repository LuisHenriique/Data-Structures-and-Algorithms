#ifndef LISTA_H
#define LISTA_H
#define inicial 0
#define ERRO -32000

#include "item.h"
#include <stdbool.h>

typedef struct lista_ LISTA;

LISTA *lista_criar(bool ordenada);
ITEM *lista_remover(LISTA *lista, int chave);
int lista_tamanho(LISTA *lista);
bool lista_vazia(LISTA *lista);
bool lista_cheia(LISTA *lista);
bool lista_inserir(LISTA *lista, ITEM *item);
bool lista_apagar(LISTA **lista);
ITEM *lista_busca(LISTA *lista, int chave);
void lista_imprimir(LISTA *lista);

#endif