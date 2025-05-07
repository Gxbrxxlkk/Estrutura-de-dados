#ifndef __HEAD_H__
#define __HEAD_H__

#include "revisao_pt2/heap/head_heap.h"

struct est_lista {
    tipo_dado* vet[MAX];
    int contador;
};
typedef struct est_lista tipo_lista;

void heapsort(tipo_lista*);

#endif