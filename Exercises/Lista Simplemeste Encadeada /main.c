#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "item.h"

int main(int argc, char *argv[])
{

    LISTA *lista;
    ITEM *item;
    lista = lista_criar(true);
    printf("\nLista criada!\n");

    lista_inserir(lista, item_criar(1, NULL));
    printf("\nChave inserida! -> 1\n");

    lista_inserir(lista, item_criar(2, NULL));
    printf("\nChave inserida! -> 2\n");

    lista_inserir(lista, item_criar(8, NULL));
    printf("\nChave inserida! -> 8\n");

    lista_inserir(lista, item_criar(12, NULL));
    printf("\nChave inserida! -> 12\n");

    lista_inserir(lista, item_criar(18, NULL));
    printf("\nChave inserida! -> 18\n");

    lista_inserir(lista, item_criar(10, NULL));
    printf("\nChave inserida! -> 10\n");

    lista_inserir(lista, item_criar(5, NULL));
    printf("\nChave inserida! -> 5\n");

    lista_imprimir(lista);
    printf("\nImpressão realizada com sucesso!\n");

    printf("\nTamanho da Lista: %d\n", lista_tamanho(lista));

    item = lista_remover(lista, 12); // remove no do meio da lista
    item_apagar(&item);              // apaga o item retornado. responsabilidade do chamado em vez de ser ser lista_remover(); decisão de projeto
    printf("\nTamanho da Lista atualizado: %d\n", lista_tamanho(lista));

    printf("\n");
    lista_imprimir(lista);
    printf("\nImpressão realizada com sucesso!\n");

    ITEM *searchItem = lista_busca(lista, 2);
    int itemFound = item_get_chave(searchItem);
    printf("\n-----Item encontrado: [%d]\n", (itemFound));

    item = lista_remover(lista, 1); // remove 1o item da lista

    item_apagar(&item);

    lista_imprimir(lista);
    printf("\nImpressão realizada com sucesso!\n");
    printf("\nTamanho da Lista atualizado: %d\n", lista_tamanho(lista));

    lista_apagar(&lista);

    return (0);
}
