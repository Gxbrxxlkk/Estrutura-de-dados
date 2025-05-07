#include "head.h"

void inicializa_heap(tipo_heap* h) {
    h->contador = 0;
    for (int i = 0; i < MAX; i++)
        h->vet[i] = NULL;
}

int pai_heap(int i) {
    return (int) (i - 1) / 2;
}

int esq_heap(int i) {
    return (int) (i*2) + 1;
}

int dir_heap(int i) {
    return (int) (i*2) + 2;
}

void sobe_heap_min(tipo_heap* h, int i) {

    int i_pai = pai_heap(i);
    if (i_pai >= 0) {
        if (h->vet[i]->chave < h->vet[i_pai]->chave) {

            tipo_dado* aux = h->vet[i_pai];
            h->vet[i_pai] = h->vet[i];
            h->vet[i] =  aux;
            sobe_heap_min(h, i_pai);

        }
    } 
}



void insere_h(tipo_heap* h, tipo_dado dado) {
    if (h->contador < MAX) {
        tipo_dado* novo = (tipo_dado*)malloc(sizeof(tipo_dado));
        *novo = dado; // Copia os dados
        h->vet[h->contador++] = novo;
        sobe_heap_min(h, h->contador - 1);
    }
}

void desce_heap_min(tipo_heap* h, int i) {
    int i_esq = esq_heap(i);
    int i_dir = dir_heap(i);
    int menor = i;

    if (i_esq < h->contador) {
        if (i_dir < h->contador) {
            if (h->vet[i_esq]->chave < h->vet[i_dir]->chave) 
                menor = i_esq;
            else
                menor = i_dir;
        } else
            menor = i_esq;        
    }
    if (h->vet[menor]->chave < h->vet[i]->chave) {
        tipo_dado* temp = h->vet[i];
        h->vet[i] = h->vet[menor];
        h->vet[menor] = temp;
        desce_heap_min(h, menor);
    }
}

tipo_dado* remove_h(tipo_heap* h) {
    if (h->contador == 0) exit(1);
    tipo_dado* dado = h->vet[0];
    h->vet[0] = h->vet[--h->contador];
    desce_heap_min(h,0);
    return dado;
}

void imprime_h(tipo_heap h) {
    printf("Contador: %d\n", h.contador);
    for (int i = 0; i < h.contador; i++)
    {
        printf("[%d] ", h.vet[i]->chave);
    }
}