#include <stdio.h>
#include <stdlib.h>
int main() {
    int valor1, valor2, total = 0, negativo = 0;
    printf("Insira 2 valores para fazer a multiplicação, separados por espaco: ");
    scanf("%d %d", &valor1, &valor2);
    
    if (valor1 < 0 && valor2 < 0)
    {
        valor1 = -valor1;
        valor2 = -valor2;
    }
    if (valor1 < 0 || valor2 < 0)
    {
        negativo = 1;
        if (valor1 < 0)
        {
            valor1 = -valor1;
        } else 
        {
            valor2 = -valor2;
        }
        
        if (valor1 > valor2) {
            int temp;
            temp = valor1;
            valor1 = valor2;
            valor2 = temp;
    }
        printf("valor 1 %d  valor 2 %d", valor1, valor2);
        for (int i= 0; i < valor2; i++)
        {
            total += valor1;
        } if (negativo)
        {
            total = -total;
        }
        
        
        
    }printf("O Resultado e %d", total);
    return 0;
}