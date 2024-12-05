#include <stdio.h>
#include <stdlib.h>

int main() {
    int valor1, total, resto = 0;
    printf("Insira um valor para fazer a divisão: ");
    scanf("%d", &valor1);
    total = valor1 / 3;
    resto = valor1 % 3;
    printf("O total da divisão de %d por 3 é: %d e o resto é: %d", valor1, total, resto);
    return 0;
}