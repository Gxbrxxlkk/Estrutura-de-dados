#include "head.h"

tipo_no* aloca_no(void* dado, int chave) {
    tipo_no* novo_no = (tipo_no*)malloc(sizeof(tipo_no));
    if(novo_no == NULL) exit(1);
    novo_no->tamanho = 0;

    for (size_t i = 0; i < MAX; i++) {
        novo_no->chave[i] = 0;
        novo_no->dado[i] = NULL;
    }
    for (size_t i = 0; i < MAX + 1; i++) {
        novo_no->filhos[i] = NULL;
    }
    novo_no->chave[0] = chave;
    novo_no->dado[0] = dado;
    novo_no->tamanho = 1;
    
    return novo_no;
}

void inserir_no(tipo_no** no, void* dado, int chave) {
    if ((*no) == NULL) {
        *no = aloca_no(dado, chave); 
        return;
    }
    if ((*no)->tamanho < MAX) {
        int i = (*no)->tamanho;
        while (i>=0 && (*no)->chave[i -1] > chave) {
            (*no)->chave[i] = (*no)->chave[i -1];
            (*no)->dado[i] = (*no)->dado[i -1];
            i--;
        }
        (*no)->chave[i] = chave;
        (*no)->dado[i] = dado;
        (*no)->tamanho++;
        return;
    } else {
        int i = 0;
        while (chave > (*no)->chave[i] && i < (*no)->tamanho)  i++;
        inserir_no(&(*no)->filhos[i], dado, chave);    
    }
}

void imprime_pre_ordem(tipo_no* no) {
    if (no == NULL) return;
    printf("[ ");
    for (int i = 0; i < no->tamanho; i++){
        printf("Chave: %d ", no->chave[i]);
    }
    printf("]");
    for (int i = 0; i <= no->tamanho; i++) {
        imprime_pre_ordem(no->filhos[i]);
    }
}

void imprime_pos_ordem(tipo_no* no) {
    if (no == NULL) return;

    // Chama recursivamente para os filhos
    for (int i = 0; i <= no->tamanho; i++) {
        imprime_pos_ordem(no->filhos[i]);
    }

    // Imprime as chaves do nó atual
    printf("[ ");
    for (int i = 0; i < no->tamanho; i++) {
        printf("Chave: %d ", no->chave[i]);
    }
    printf("] ");
}

void imprime_em_ordem(tipo_no* no) {
    if (no == NULL) return;

    for (int i = 0; i < no->tamanho; i++)
    {
        imprime_em_ordem(no->filhos[i]);
        printf("Chave: %d ", no->chave[i]);
    }
    if (no->filhos[no->tamanho] != NULL) {
        imprime_em_ordem(no->filhos[no->tamanho]);
    }
}

tipo_no* busca_no(tipo_no* no, int chave) {
    if (no == NULL) return NULL;

    for (int i = 0; i < no->tamanho; i++)
    {
        if (no->chave[i] == chave) return no;
    }
    int i = 0;
    while (i < no->tamanho && chave > no->chave[i])
        i++;
    return busca_no(no->filhos[i], chave);
}

int total_nos(tipo_no *no) {
    if (no == NULL) return 0;

    int total = 1; // Conta o nó atual
    for (int i = 0; i <= no->tamanho; i++) {
        total += total_nos(no->filhos[i]); // Soma os nós dos filhos
    }
    return total;
}

int total_folhas(tipo_no* no) {
    if (no == NULL) return 0;

    // Verifica se o nó é uma folha
    int eh_folha = 1;
    for (int i = 0; i <= no->tamanho; i++) {
        if (no->filhos[i] != NULL) {
            eh_folha = 0;
            break;
        }
    }

    // Se for folha, retorna 1
    if (eh_folha) return 1;

    // Caso contrário, soma as folhas dos filhos
    int total = 0;
    for (int i = 0; i <= no->tamanho; i++) {
        total += total_folhas(no->filhos[i]);
    }
    return total;
}

int verifica_folha(tipo_no* no, int chave) {
    tipo_no* no_alvo = busca_no(no, chave);
    if (no_alvo == NULL)
    return 0;
    

    for (int i = 0; i <= no->tamanho; i++)
    {
        if (no_alvo->filhos[i] != NULL) return 0;
    }
    return 1;
}

int altura_arvore(tipo_no* no) {
    if (no == NULL) return 0; // Caso base: árvore vazia

    int altura_maxima = 0;

    // Percorre todos os filhos do nó atual
    for (int i = 0; i <= no->tamanho; i++) {
        int altura_filho = altura_arvore(no->filhos[i]); // Calcula a altura do filho
        if (altura_filho > altura_maxima) {
            altura_maxima = altura_filho; // Atualiza a maior altura encontrada
        }
    }

    return 1 + altura_maxima; // Altura do nó atual + maior altura dos filhos
}
int busca_maior(tipo_no* no) {
    if (no == NULL) return -1;

    if (no->filhos[no->tamanho] != NULL)
        return busca_maior(no->filhos[no->tamanho]);
    
    return no->chave[no->tamanho - 1];
}

int busca_menor(tipo_no* no) {
    if (no == NULL) return -1;

    if (no->filhos[0] != NULL)
        return busca_menor(no->filhos[0]);
    return no->chave[0];
}

void imprime_nivel(tipo_no* no, int nivel) {
    if (no == NULL) return;

    if (nivel == 0) {
        printf("[ ");
        for (int i = 0; i < no->tamanho; i++)
        {
            printf("%d ", no->chave[i]);
        }
        printf("] ");
    } else {
        for (int i = 0; i <= no->tamanho; i++)
        {
            imprime_nivel(no->filhos[i], nivel - 1);
        }
    }
}

void imprime_arv_nivel(tipo_no* no) {
    int h = altura_arvore(no);

    for (int i = 0; i < h; i++)
    {
        printf("Nivel: %d: ", i);
        imprime_nivel(no, i);
        printf("\n");
    }
}

int contabiliza_no_por_nivel(tipo_no* no, int nivel) {
    if (no == NULL) return 0;
    int total = 0;

    if (nivel == 0) return 1;
    else {
        for (int i = 0; i <= no->tamanho; i++)
        {
            total += contabiliza_no_por_nivel(no->filhos[i], nivel - 1);
        }
    }
    return total;
}

void imprime_rota(tipo_no* no, int chave) {
    if (no == NULL) return;

    printf("[ ");
    for (int i = 0; i < no->tamanho; i++) {
        printf("%d ", no->chave[i]);
    }
    printf("] ");

    int i = 0;
    while (i < no->tamanho && chave > no->chave[i]) {
        i++;
    }
    if (no->filhos[i] != NULL) {
        imprime_rota(no->filhos[i], chave);
    }
}