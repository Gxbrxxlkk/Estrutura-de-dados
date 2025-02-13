/**
 * Encadeamento de nós
 * 
 * O nó deve conter o dado e um componente que permite o encadeamento(ponteiro)
 * Estrutura do nó:
 * Tipo nó\/ \\ 
 * [tipo dado][*] <---------
 * ponteiro para o tipo nó/\
 * para armazenar um inteiro, nosso nó será, por exemplo:
 * tipo_no {
 *  inteiro valor;
 *  tipo_no *prox;
 * }
 * Devemos ter um ponteiro que **sempre** aponta para o inicio da estrutura
 * usar um ponteiro auxiliar para armazenar o endereço do primeiro elemento
 * fazer uma variavel para criar novo nó, para o ponteiro auxiliar receber e colocar no nó anterior
 * if fila == null? nao, else *aux = *fila 
 * ponteiro novo nó alocar memoria, guardar ponteiro nulo e inserir novo valor, atualize aux para o novo nó
 * if *prox == null, fila = fila->null?
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valor;
    tipo_no *prox;
} tipo_no;

tipo_no *aloca_no(int valor) {
    tipo_no *novo_no;

    novo_no = (tipo_no*) malloc(sizeof(tipo_no));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    return novo_no;
}
void inserefila(tipo_no **fl, int valor){
if ((*fl) == NULL) {
    (*fl) = aloca_no(valor);
} else {
    tipo_no *aux, *novo_no;
    aux = (*fl);
    while (aux->prox != NULL)
        aux = aux->prox;
    
    novo_no = aloca_no(valor);
    aux->prox = novo_no;
    
}

}
int removefila(tipo_no**);
int primeirofila(tipo_no*);
int imprimefila(tipo_no*);

int main() {
tipo_no *fila;
fila = NULL;


}