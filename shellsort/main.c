#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    
    ListaEstatica lista;
    inicializar(&lista);
    srand(time(0));
    for (size_t i = 0; i < MAX; i++)
    {
        lista.vetor[i] = gerarrandom();
        lista.tamanho++;
    }
    imprimir(&lista);
    shellsort(&lista);
    imprimir(&lista);
}//Lembrar de fazer o merge sort