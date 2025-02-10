/**
 * 1 2 3 4 5 6 7
 * Remove 1, coloca 2 pro final
 * 3 4 5 6 7 2
 * Remove 3, coloca 4 pro final
 * 5 6 7 2 4
 * Remove 5, coloca 6 pro final
 * 7 2 4 6
 * Remove 7, coloca 2 pro final
 * 4 6 2
 * Remove 4, coloca 6 pro final
 * 2 6
 * Remove 2, sobra 6
 */


#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50

typedef struct
{
    int baralho[TAMANHO], inicio, fim;
} Cartas;

void inicializar(Cartas* baralho) {
    baralho -> inicio = -1;
    baralho -> fim = -1;
}
int filavazia(Cartas* baralho) {
    return baralho->inicio==-1;
}
int filacheia(Cartas* baralho){
    return ((baralho->fim +1) % TAMANHO) == baralho->inicio;
}
void enfileirar(Cartas* baralho, int valor){
    if(filacheia(baralho)){
        printf("Fila cheira\n");
        return;
    }
    if (filavazia(baralho))
    {
        baralho->inicio = 0;
    }
    baralho->fim = (baralho->fim + 1) % TAMANHO;
    baralho->baralho[baralho->fim] = valor;
    
}

int desinfileirar(Cartas* baralho) {
    if (filavazia(baralho))
    {
        printf("A fila esta vazia");
        return -1;

    }
    int valor = baralho->baralho[baralho->inicio];
    if (baralho->inicio == baralho->fim) {
        baralho->inicio = -1;
        baralho->fim = -1;
    } else {
        baralho->inicio = (baralho->inicio + 1) % TAMANHO;
    }
    return valor; // Retorna sempre
}


int primeiroelemento(Cartas* baralho) {
    if (filavazia(baralho))
    {
        printf("Filha vazia");
        return -1;
    }
    return baralho->baralho[baralho->inicio];
}

int main() {
    int True = 1;
    while (True) {   
        Cartas fila;
        inicializar(&fila);
        int tamanhobaralho, descartados[TAMANHO], k = 0;
        scanf("%d", &tamanhobaralho);
        
        if (tamanhobaralho == 0) {
            True = 0;
        } else {
            // Preenche a fila
            for (int i = 0; i < tamanhobaralho; i++) {
                enfileirar(&fila, i+1);
            }

            // Processa até sobrar 1 carta
            while (!filavazia(&fila) && fila.inicio != fila.fim) {
                descartados[k++] = desinfileirar(&fila);
                int transfere = desinfileirar(&fila);
                enfileirar(&fila, transfere);
            }

            // Imprime resultado
            printf("Discarded cards: ");
            for (int i = 0; i < k; i++) {
                if (i < k - 1) {
                    printf("%d, ", descartados[i]); // Vírgula para todos, exceto o último
                } else {
                    printf("%d", descartados[i]);   // Último elemento sem vírgula
                }
            }
            printf("\nRemaining card: %d\n", desinfileirar(&fila));
        }
    }
    return 0;
}