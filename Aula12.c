/**
 * Lista com encadeamento duplo
 * Usa os mesmos princípios da lista com encadeamento "simples"
 * Busca facilitar algumas operações, evitando a necessidade de ponteiros auxiliares adicionais. 
 * No entanto, demanda mais memória
 * É preciso ter mais atenção em razão de um ponteiro da estrutura que precisa ser zero
 * Estrutura do nó:
 * 
 * [*][valor][*]
 * ant/valor/próx
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct Lista_dup {
    int valor;
    struct Lista_dup* proximo; 
    struct Lista_dup* anterior; 
} Lista_dup;

void inserir_inicio(Lista_dup** cabeca, int valor);
void inserir_fim(Lista_dup** cabeca, int valor);
void remover_no(Lista_dup** cabeca, int valor);
Lista_dup* buscar(Lista_dup* cabeca, int valor);
void imprimir_lista(Lista_dup* cabeca);

int main() {

    return 0;
}

void inserir_inicio(Lista_dup** cabeca, int valor) {
    Lista_dup* novo_no = (Lista_dup*)malloc(sizeof(Lista_dup));
    novo_no->valor = valor;
    novo_no->proximo = *cabeca;
    novo_no->anterior = NULL;

    if (*cabeca != NULL) {
        (*cabeca)->anterior = novo_no;
    }
    *cabeca = novo_no;
}

void inserir_fim(Lista_dup** cabeca, int valor) {
    Lista_dup* novo_no = (Lista_dup*)malloc(sizeof(Lista_dup));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    
    if (*cabeca == NULL) {
        novo_no->anterior = NULL;
        *cabeca = novo_no;
        return;
    }
    Lista_dup* temp = *cabeca;
    while (temp->proximo != NULL)
    {
        temp = temp->proximo;
    }
    temp->proximo = novo_no;
    novo_no->anterior = temp;

}
void remover_no(Lista_dup** cabeca, int valor){
    Lista_dup* temp = *cabeca;
    while (temp != NULL && temp->valor != valor)
    {
        temp = temp->proximo;
    }
    
    if (temp == NULL)
    {
        printf("Valor não encontrado na lista.\n");
        return;
    }
    if (temp->anterior != NULL)
    {
        temp->anterior->proximo = temp->proximo;
    }   else
    {
        *cabeca = temp->proximo;
    }
    if (temp->proximo != NULL)
    {
        temp->proximo->anterior = temp->anterior;
    }
    free(temp);
}

Lista_dup* buscar(Lista_dup* cabeca, int valor){
    Lista_dup* temp = cabeca;

    while (temp != NULL && temp->valor != valor)
    {
        temp = temp->proximo;
    }
    return temp;
}

void imprimir_lista(Lista_dup* cabeca) {
    Lista_dup* temp = cabeca;

    while (temp != NULL)
    {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
    
}