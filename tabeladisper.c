/**
 * Tabela de disperção (Tabela hash)
 * 
 * 1ª estrutura que usa código identificador;
 * Usa um vetor como componennte p/ armazenamento,
 * Os dados ficam dispersos no vetor;
 * Existe uma função que determina a posição do dado na tabela
 *  Função hash
 * 
 * Uma tabela hash não deve ficar cheia
 * Recomenda-se uma utilização de até 80% da sua capacidade.
 * fh(chave) = resto(chave/tamanho)  (funçao hash)
 * 1º identificar a chave
 * 2º Descobrir o indice por meio da fh
 * 3º Acessar o indice
 * 4º Tratar colisão, *caso ocorra*
 * tabela com varios ponteiros para lista dinâmica,
 * caso uma chave não está na tabela, retorna que não encontrou
 * Na hora de inserir, alocar um nó para o item no indice que a função retorna, e caso já tenha, passe e crie um nó
 */

#include "tabeladisper.h"

void inicializar(tabela_hash *l) {

    for (size_t i = 0; i < MAX; i++)
        l->vet[i] = NULL;
}

lista_hash* aloca_no(int chav, int val) {
    lista_hash *novo_no = (lista_hash*)malloc(sizeof(lista_hash));
    novo_no->valor = val;
    novo_no->chave = chav;
    novo_no->prox = NULL;
    return novo_no;
}

int funcao_hash(int chave){    
    return chave % MAX;
}

void insereTabHash(tabela_hash* l,int chav, int val) {
    int indice = funcao_hash(chav);

    if (l->vet[indice] == NULL)
    {
        l->vet[indice] = aloca_no(chav, val);
    }   else {

        lista_hash *aux = l->vet[indice];
        
        while (aux->prox != NULL) { //Da pra fazer inserção no inicio também, é mais rapido, ja que a ordem não importa
            aux = aux->prox;
        }
        aux->prox = aloca_no(chav, val);    
    }
}

int removeTabHash(tabela_hash *l, int chav) {
    int indice = funcao_hash(chav); 

    lista_hash *aux = l->vet[indice];
    lista_hash *anterior = NULL;


    while (aux != NULL && aux->chave != chav) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        l->vet[indice] = aux->prox; 
    } else {
        anterior->prox = aux->prox; 
    }

    free(aux); 
    return 1; 
}

void imprimeTabHash(tabela_hash *t) {
    for (int i = 0; i < MAX; i++) {
        printf("Índice %d: ", i);
        lista_hash *aux = t->vet[i];
        while (aux != NULL) {
            printf("(%d, %d) -> ", aux->chave, aux->valor);
            aux = aux->prox;
        }
        printf("NULL\n");
    }
}

int buscaTabHash(tabela_hash *l, int chav) {
    int indice = funcao_hash(chav);  

    lista_hash *aux = l->vet[indice];
    while (aux != NULL) {
        if (aux->chave == chav) {
            return aux->valor; 
        }
        aux = aux->prox;
    }
    return -1;
}