/*
UFMT - Universidade Federal de Mato Grosso
Estrutura de Dados I
Professor Ivairton
*/

#include <stdio.h>
#include <stdlib.h>

// '*' Ponteiro é uma variavel especial que guarda endereço de memória

    int soma(int, int);
    int multiplicacao(int*,int*);

int main() {
    int x, y, resultado;
    printf("Informe o valor1: ");
    scanf("%d", &x);
    printf("Informe o valor2: ");
    scanf("%d", &y);

    resultado = soma(x, y);
    printf("Resultado da soma: %d\n", resultado);

    resultado = multiplicacao(&x, &y);
    printf("O resultado da multiplicação é: %d", resultado);

}

int soma(int valor1, int valor2) {
    return valor1 + valor2;

}
int multiplicacao(int *valor1, int *valor2) {

    return *valor1 * *valor2;
}