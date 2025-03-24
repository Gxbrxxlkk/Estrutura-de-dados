#ifndef __TABELADISPER_H__
#define __TABELADISPER_H__

#include <stdlib.h>
#include<stdio.h>

#define MAX 10

typedef struct lista_hash {
    int chave;
    int valor;
    struct lista_hash *prox;
}lista_hash;

typedef struct tabela_hash {
    struct lista_hash* vet[MAX];
}tabela_hash;


void inicializar(tabela_hash *l);
lista_hash* aloca_no(int chav, int val);
int funcao_hash(int chave);
void insereTabHash(tabela_hash*, int, int);
int removeTabHash(tabela_hash*, int);
int buscaTabHash(tabela_hash*, int);
void imprimeTabHash(tabela_hash*);

#endif