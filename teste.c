#include <stdio.h>
#include <stdlib.h>

int main() {

    int valor1, valor2;
    printf("Insira 2 numeros inteiros separados por espaco: ");
    scanf("%d %d", &valor1, &valor2);

    if (valor2 < valor1) {
        for (valor2; valor2 <= valor1; valor2++) {
            printf("%d",valor2);
        }
        
    }
    

    return 0;
}
