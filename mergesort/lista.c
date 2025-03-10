#include "lista.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void inicializar(ListaEstatica* lista) {
    lista->tamanho = 0;
    return;
}

void inserirrand(ListaEstatica* lista) {

    srand(time(NULL));

    for (size_t i = 0; i < MAX; i++)
    {
        lista->vetor[i] = rand() % 10;
        lista->tamanho++;
    }
    return;
}

void imprimir(ListaEstatica* lista) {

    for (size_t i = 0; i < MAX; i++)
    {
        printf("[%d] ", lista->vetor[i]);
    }
    printf("\n");
    return;
}

void mergesort(ListaEstatica* lista) {

int pos_esq = 0, pos_dir = MAX - 1;

while (pos_esq != pos_dir)
{
    int metade = (lista->tamanho - 1) / 2;
    ListaEstatica nova_lista;
    for (size_t i = 0; i < metade; i++)
    {
        nova_lista.vetor[i] = lista->vetor[i];
    }
    
    
}


}