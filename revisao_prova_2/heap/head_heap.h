#ifndef __HEAD_HEAP_H__
#define __HEAD_HEAP_H__

#include <stdlib.h>
#include <stdio.h>

#define MAX 20

struct est_dados {
    int chave;
    void* dado;
};
typedef struct est_dados tipo_dado;

struct est_heap {
    tipo_dado* vet[MAX];
    int contador;
};
typedef struct est_heap tipo_heap;

void inicializa_heap(tipo_heap*);
int pai_heap(int);
int esq_heap(int);
int dir_heap(int);
void sobe_heap_min(tipo_heap*, int);
void insere_h(tipo_heap*, tipo_dado);
void desce_heap_min(tipo_heap*, int);
tipo_dado* remove_h(tipo_heap*);
void imprime_h(tipo_heap);


#endif