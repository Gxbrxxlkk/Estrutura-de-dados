#include "head_arbin.h"

tipo_no* aloca_no(int chave, void* dado) {
    tipo_no* novo_no = (tipo_no*)malloc(sizeof(tipo_no));
    if (novo_no == NULL) return;
    novo_no->chave = chave;
    novo_no->dado = dado;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

void insere_no(tipo_no** no, int chave, void* dado) {
    if ((*no) == NULL) (*no) = aloca_no(chave, dado);

    else {
        if (chave < (*no)->chave)
        {
            insere_no(&(*no)->esq, chave, dado);
        } else insere_no(&(*no)->dir, chave, dado);
    }
}

void imprime_pre_ordem(tipo_no* no) {
    if (no == NULL) return;
    printf("[%d] ", no->chave);
    imprime_pre_ordem(no->esq);
    imprime_pre_ordem(no->dir);
}

void imprime_em_ordem(tipo_no* no) {
    if (no == NULL) return;
    imprime_em_ordem(no->esq);
    printf("[%d] ", no->chave);
    imprime_em_ordem(no->dir);
}

void imprime_pos_ordem(tipo_no* no) {
    if (no == NULL) return;
    imprime_pos_ordem(no->esq);
    imprime_pos_ordem(no->dir);
    printf("[%d] ", no->chave);
}

int total_nos(tipo_no* no) {
    if (no == NULL) return 0;
    else return 1 + total_nos(no->esq) + total_nos(no->dir);
}

int total_folhas(tipo_no* no) {
    if (no == NULL) return 0;
    if (no->esq == NULL && no->dir == NULL) {
        return 1;
    }
    return total_folhas(no->esq) + total_folhas(no->dir);
}

tipo_no* busca_no(tipo_no* no, int chave) {
    if (no == NULL) return NULL;
    else if (no->chave == chave) return no;
    else if (chave < no->chave) return busca_no(no->esq, chave);
    else return busca_no(no->dir, chave);
}

int verifica_folha(tipo_no* no,int chave) {
    if (no == NULL) return 0;
    tipo_no* no_alvo = busca_no(no, chave);
    if (no_alvo->esq == NULL && no_alvo->dir == NULL) {
        return 1;
    }
}

int altura_arvore(tipo_no* no) {
    if (no == NULL) return 0;
    int alt_esq = altura_arvore(no->esq);
    int alt_dir = altura_arvore(no->dir);
    return 1 + (alt_esq > alt_dir ? alt_esq : alt_dir);
}

void imprime_nivel(tipo_no* no, int nivel) {
    if (no == NULL) return;
    if (nivel == 0) {
        printf("[ %d ] ", no->chave);
    } else {
        imprime_nivel(no->esq, nivel - 1);
        imprime_nivel(no->dir, nivel - 1);
    }
}

void imprime_arv_nivel(tipo_no* no) {
    int h = altura_arvore(no);
    for (int i = 0; i < h; i++) {
        printf("Nivel %d: ", i);
        imprime_nivel(no, i);
        printf("\n");
    }
}

int contabiliza_no_nivel(tipo_no* no, int nivel) {
    if (no == NULL) return 0;
    if (nivel == 0) return 1;
    return contabiliza_no_nivel(no->esq, nivel - 1) + contabiliza_no_nivel(no->dir, nivel - 1);
}

void imprime_rota(tipo_no* no, int chave) {
    if (no == NULL) {
        printf("Chave %d não encontrada.\n", chave);
        return;
    }
    printf("[ %d ] ", no->chave);
    if (no->chave == chave) {
        printf("\n");
        return;
    }
    if (chave < no->chave)
        imprime_rota(no->esq, chave);
    else
        imprime_rota(no->dir, chave);
}

tipo_no* busca_maior_no(tipo_no* no) {
    if (no == NULL) return NULL;
    while (no->dir != NULL)
        no = no->dir;
    return no;
}

tipo_no* busca_menor_no(tipo_no* no) {
    if (no == NULL) return NULL;
    while (no->esq != NULL)
        no = no->esq;
    return no;
}

tipo_no* remove_no(tipo_no* no, int chave) {
    if (no == NULL) return NULL;
    if (chave < no->chave) {
        no->esq = remove_no(no->esq, chave);
    } else if (chave > no->chave) {
        no->dir = remove_no(no->dir, chave);
    } else {
        // Nó com apenas um filho ou nenhum
        if (no->esq == NULL) {
            tipo_no* temp = no->dir;
            free(no);
            return temp;
        } else if (no->dir == NULL) {
            tipo_no* temp = no->esq;
            free(no);
            return temp;
        }
        // Nó com dois filhos: pega o menor da subárvore direita
        tipo_no* temp = busca_menor_no(no->dir);
        no->chave = temp->chave;
        no->dado = temp->dado;
        no->dir = remove_no(no->dir, temp->chave);
    }
    return no;
}

