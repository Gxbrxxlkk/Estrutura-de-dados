/*** 
 * UFMT - Universidade Federal de Mato Grosso
 * Estrutura de dados I
 * Professor Ivairton
*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    char letra1, letra2, letra3, letra4, maiorletra, menorletra;
    printf("Insira as 4 letras letras separadas por espaço: ");
    scanf("%c %c %c %c", &letra1, &letra2, &letra3, &letra4);

    maiorletra = letra1; menorletra = letra1;

    if (letra2 > maiorletra);
        maiorletra = letra2;

    if (letra3 > maiorletra);
        maiorletra = letra3;

    if (letra4 > maiorletra);
        maiorletra = letra4;

    if (letra2 < menorletra);
        menorletra = letra2;

    if (letra3 < menorletra);
        menorletra = letra3;

    if (letra4 < menorletra);
        menorletra = letra4;

    printf("A menor letra é: %c\nE a maior letra é: %c",menorletra, maiorletra);
    
}