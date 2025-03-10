#include "lista.h"
#include <stdio.h>
int main() {

    ListaEstatica lista;
    inicializar(&lista);
    inserirrand(&lista);
    imprimir(&lista);
    printf("Tamanho do vet: %d", lista.tamanho);

}