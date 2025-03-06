#ifndef __LISTA_H__
#define __LISTA_H__
#define MAX 10

typedef struct ListaEstatica
{
    int tamanho;
    int vetor[MAX];

}ListaEstatica;

void inicializar(ListaEstatica *L);
void inserir(ListaEstatica *L, int val);
int remover(ListaEstatica *L, int index);
void imprimir(ListaEstatica *L);
void bublesort(ListaEstatica *L);

