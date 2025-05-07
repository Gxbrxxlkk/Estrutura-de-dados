#ifndef __HEAD_H__
#define __HEAD_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 100

struct est_no
{
    int chave;
    void* dado;
    struct est_no* prox;
};
typedef struct est_no tipo_no;

struct est_hash
{
    tipo_no* vet[MAX];
};
typedef struct est_hash tipo_hash;

void inicializa_tab_hash(tipo_hash*);
int funcao_hash(int);
tipo_no* aloca_no(int, void*);
void insere(tipo_hash*, int, void*);
int remove_tab_hash(tipo_hash*, int);
tipo_no* busca_tab_hash(tipo_hash*, int);
void imprime(tipo_hash*);

typedef void (*print_func)(void*);

#endif