/*** 
 * UFMT - Universidade Federal de Mato Grosso
 * Estrutura de dados I
 * Professor Ivairton
*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    int valor1, valor2, valor3;
    float media;
    
    printf("Insira sua primeira nota: \n");
    scanf("%d", &valor1);
    printf("Insira sua segunda nota: \n");
    scanf("%d", &valor2);
    printf("Insira sua terceira nota: \n");
    scanf("%d", &valor3);
    media = (valor1 +valor2 + valor3)/3;
    printf("Sua média é %f\n", media);
    if (media == valor1) {
        printf("A sua primeira nota é igual a média");
    } else if (media == valor2) {
        printf("A sua segunda nota é igual a média");
    } else if (media == valor3) {
        printf("A sua terceira nota é igual a média");
    } else {
        printf("Nenhuma das suas notas é igual a média");
    }
}