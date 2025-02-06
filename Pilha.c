/*
Pilha (First-in, Last-out, filo)
primeiro item será o ultimmo a ser retirado
O Mesmo "Lado" é usado para a inserção e remoção
Apenas 2 ações são possíveis na pilha:
Empilha ()
Desempilha ()
Em alguns casos podemos implementar a função "topo", que apenas "Olha" o elemento do topo.

fazer fila e pilha
*/


#include <stdio.h>
#include <stdlib.h>

#define TAM_VET 10
typedef struct {
    int dados[TAM_VET], topo, capacidade;
} Pilha;

//Protótipo das funções

void inicializar(Pilha *pilha);
int pilhacheia(Pilha *pilha);
int pilhavazia(Pilha *pilha);
void push(Pilha *pilha, int valor);
int pop(Pilha *pilha);
int peek(Pilha *pilha);

//Declaração das funções

void inicializar(Pilha *pilha) {

    pilha->topo = -1;
    pilha->capacidade = TAM_VET;

}

int pilhavazia(Pilha *pilha) {
    return (pilha->topo == -1);
}
int pilhacheia(Pilha *pilha) {

    return (pilha->topo == pilha->capacidade-1);

}
void push(Pilha *pilha, int valor) {
    if (pilhacheia(pilha)) {
        printf("A pilha está cheia!\n");
        return;
    }

    pilha->dados[++pilha->topo] = valor;
}

int pop(Pilha *pilha) {
    
    if (pilhavazia(pilha)) {
        printf("Pilha está vazia\n"); 
        return -1;    
    }
    return pilha->dados[pilha->topo--];
}
int peek(Pilha *pilha) {
    if (pilhavazia(pilha)){
        printf("A Pilha está vazia, nada para olhar.\n");
        return -1;
    }
    return pilha->dados[pilha->topo];
}
