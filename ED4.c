#include <stdio.h>
#include <stdlib.h>

int main() {
    int valor1, valor2, total = 0, negativo = 0;
    printf("Insira 2 valores para fazer a multiplicação, separados por espaco: ");
    scanf("%d %d", &valor1, &valor2);
    
    
    if (valor1 < 0 && valor2 < 0) {
        valor1 = -valor1;  
        valor2 = -valor2;
    } else if (valor1 < 0 || valor2 < 0) {
        
        negativo = 1;
        if (valor1 < 0) {
            valor1 = -valor1;  
        } else {
            valor2 = -valor2;  
        }
    }

    
    if (valor1 > valor2) {
        int temp = valor1;
        valor1 = valor2;
        valor2 = temp;
    }

    
    for (int i = 0; i < valor1; i++) {
        total += valor2;  
    }

    if (negativo) {
        total = -total;
    }

    printf("O resultado da multiplicação é: %d\n", total);

    return 0;
}
