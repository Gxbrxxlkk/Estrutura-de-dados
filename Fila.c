/**
 * Criar uma fila
 * first in, first out fifo
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM_VET 10

typedef struct
{
    int dados[TAM_VET];
    int contador, capacidade, frente, atras;

} Fila;

int Enqueue(Fila *fila, int valor);
int Dequeue(Fila *fila);
void Peek(Fila *fila);
int filavazia(Fila *fila);
int filacheia(Fila *fila);



