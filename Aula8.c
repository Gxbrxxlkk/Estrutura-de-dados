/**
 * Estrutura com maior dinâmica na aplicação
 * 
 * Pode-se manipular valor em qualquer posição (valida)
 * 
 * Pode-se:
 * Inserir no inicio
 * Inserir no fim
 * Inserir em posição especifica
 * Remover do inicio
 * Remover do fim
 * Remover de posição especifica (Colocar os valores a frente do retirado para preencher possiveis lacunas)
 * Remover valor especifico
 * Ordernar
 * Etc...
 * 
 * Em lista não  se pode deixar espaço vago entre valores, se a lista está vazia, preencher de forma linear
 */



#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct 
{
    int lista[MAX], fim, tamanho, contador;
}Lista;

void inicializar(Lista *fila);
void inserircomeco(Lista *fila, int valor);
void inserirfinal(Lista *fila, int valor);
void inserirposespec(Lista *fila, int valor);
int removerinicio(Lista *fila, int valor);
int removerfinal(Lista *fila, int valor);
int removerespec(Lista *fila, int valor);
void imprimirfila(Lista *fila);

void inicializar(Lista *fila){
    fila->tamanho = MAX;
    fila->fim = -1;
    fila->contador = 0;

}

void inserircomeco(Lista *fila, int valor){


    


}

int main() {





    return 0;
}