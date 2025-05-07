#include "head.h"

void inicializa_tab_hash(tipo_hash* h) {

    for (int i = 0; i < MAX; i++) 
        h->vet[i] = NULL;
}

tipo_no* aloca_no(int chave, void* dado) {
    tipo_no* novo_no = (tipo_no*)malloc(sizeof(tipo_no));
    if (novo_no == NULL) exit(1);

    novo_no->chave = chave;
    novo_no->dado = dado;
    novo_no->prox = NULL;
    return novo_no;
}

int funcao_hash(int chave) {
    return chave%MAX;
}

void insere(tipo_hash* h, int chave, void* dado) {
    tipo_no* novo_no = aloca_no(chave, dado);

    int i = funcao_hash(chave);
    if (h->vet[i] != NULL) {
        tipo_no* temp = h->vet[i];
        h->vet[i] = novo_no;
        novo_no->prox = temp;
    } else
        h->vet[i] = novo_no;
}

int remove_tab_hash(tipo_hash* h, int chave) {
    if (h == NULL) exit(1);

    int i = funcao_hash(chave);
    tipo_no* aux = h->vet[i];
    tipo_no* ant = NULL;
    while (aux != NULL && chave != aux->chave) {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL) return -1;
    if (ant == NULL) h->vet[i] = aux->prox;
    else ant->prox = aux->prox;

    int chav = aux->chave;
    free(aux);
    return chav;
}

tipo_no* busca_tab_hash(tipo_hash* h, int chave) {
    if(h == NULL) exit(1);

    int i = funcao_hash(chave);
    tipo_no* aux = h->vet[i];
    while (aux != NULL) {
        if (aux->chave == chave) return aux;
        aux = aux->prox;
    }
    return NULL;
}

/*
void imprime(tipo_hash* h) {
    for (int i = 0; i < MAX; i++) {
        tipo_no* aux = h->vet[i];
        if (aux != NULL) {
            printf("Posição %d:", i);
            while (aux != NULL) {
                printf(" %d", aux->chave);
                aux = aux->prox;
            }
            printf("\n");
        }
    }
}
*/
void imprime(tipo_hash* h, print_func imprimir_dado) {
    for (int i = 0; i < MAX; i++) {
        tipo_no* aux = h->vet[i];
        if (aux != NULL) {
            printf("Posição %d:", i);
            while (aux != NULL) {
                printf(" %d -> ", aux->chave);
                imprimir_dado(aux->dado);  // usa a função passada
                aux = aux->prox;
            }
            printf("\n");
        }
    }
}

