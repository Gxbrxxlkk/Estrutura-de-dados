#include "lista.h"
#include <stdio.h>

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
    L->tamanho--
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

void bublesort(ListaEstatica *L) {
    if (L->tamanho == 0)
    {
        printf("Erro! Não foi possivel ordernar, lista não existe");
        return;
    }
    int flag = 1, aux;
    while (flag)
    {     
        flag = 0;
        for (size_t i = 0; i < L->tamanho - 1; i++)
        {
            if (L->vetor[i] < L->vetor[i+1])
            {
                aux = L->vetor[i];
                L->vetor[i] = L->vetor[i+1];
                L->vetor[i+1] = aux; 
                flag = 1;
            }
        }
    }
    imprimir(ListaEstatica* L);
}