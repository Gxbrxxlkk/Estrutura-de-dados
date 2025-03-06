#include "lista.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void inicializar(ListaEstatica *L) {
    L->tamanho = 0;
}

void inserir(ListaEstatica *L, int val) {
    if (L->tamanho < MAX)
    {
        L->vetor[L->tamanho] = val;
        L->tamanho++;
    } else {
        printf("Erro, a lista está cheia!\n");
        return;
    }
}

int remover(ListaEstatica *L, int index) {

    if (index<0 && index >= L->tamanho)
    {
        printf("Erro! posição inválida!\n");
        return -1;
    }
    int saida = L->vetor[index];
    for (int i = index; i < L->tamanho - 1; i++)
    {
        L->vetor[L->tamanho] = L->vetor[L->tamanho + 1];

    } 
    L->tamanho--;
    return saida;
} 

void imprimir(ListaEstatica *L) {
    if (L->tamanho == 0)
    {
        printf("Erro! A lista está vazia.\n");
        return;
    }
    for (size_t i = 0; i < L->tamanho; i++)
    {
        printf("%d ", L->vetor[i]);
    }
    printf("\n");
}
void shellsort(ListaEstatica *L) {
    if (L->tamanho == 0)
    {
        printf("Erro, a lista está vazia!\n");
        return;
    }
    int flag = 1, aux;

    while (flag)
    {
        int salto = (L->tamanho)/2;
        flag = 0;
        for (int i = 0; i < L->tamanho - 1; i += salto)
        {
            if (L->vetor[i] > L->vetor[i+=salto])
            {
                aux = L->vetor[i];
                L->vetor[i] = L->vetor[i+=salto];
                L->vetor[i+=salto] = aux;
                flag = 1;
            }
        } salto = salto/2;
    }
    imprimir(L);
}
int gerarrandom() {
    return rand() % 100 + 1; 
}