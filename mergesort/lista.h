#ifndef __LISTA_H__
#define __LISTA_H__

#define MAX 10

typedef struct ListaEstatica
{
    int tamanho;
    int vetor[MAX];

}ListaEstatica;

void inicializar(ListaEstatica*);
void inserirrand(ListaEstatica*);
void imprimir(ListaEstatica*);
void mergesort(ListaEstatica*);

#endif //__LISTA_H__