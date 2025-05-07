#include "head.h"

void heapsort(tipo_lista* l) {
    if (l == NULL) exit(1);
    tipo_heap* h = (tipo_heap*)malloc(sizeof(tipo_heap));
    inicializa_heap(h);
    for (int i = 0; i < l->contador; i++)
    {
        tipo_dado* dado = l->vet[i];
        insere_h(h, *dado);
    }
    for (int i = 0; i < l->contador; i++)
    {
        tipo_dado* dado = remove_h(h);
        l->vet[i] = dado;
    }
    free(h);
}