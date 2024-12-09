/*
* UFMT - Universidade Federal de Mato Grosso
* Professor Ivairton
* Estrutura de dados 1
*/

/* Operadores logicos
* && AND
* || OR
* ! NOT
* ^ OR exclusivo
* ~ Complemento de um
* >> deslocamento para à esquerda
* << deslocamento para à direita
* Tudo que não é zero é verdadeiro
* # Diretriz de pré compilação, vem fora da main
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int vetor[5], vetor2[5], vetresult[5], i, result,tamanhovet, valor, vetpot[5];

    for (i = 0; i < 5 ; i++) {
        vetor[i] = 0;
    }
    for (i = 0; i < 5 ; i++)
    {
        printf("Insira um valor inteiro: ");
        scanf("%d", &valor);
        vetor[i] = valor;
    }
    for ( i = 0; i < 5; i++)
    {
        printf("Insira os valores do segundo vetor: ");
        scanf("%d", &valor);
        vetor2[i] = valor;
    }
    for (i = 0 ; i < 5; i++) {

        vetresult[i] = vetor[i] +  vetor2[i];
        printf("O valor da soma no indice %d é: %d \n", i, vetresult[i]);
    }
    int menor = vetresult[0];
    for ( i = 0; i < 5; i++)
    {
        if (vetresult[i] < menor) {
            menor = vetresult[i];
        }
    }
    int maior = vetresult[0];
    for ( i = 0; i < 5; i++)
    {
        if (vetresult[i] > maior) {
            maior = vetresult[i];
        }
    }
    printf("O menor valor do vetor resultante é %d e o maior é %d\n", menor,maior);

    for ( i = 0; i < 5; i++)
    {
        tamanhovet = 5;
            vetpot[i] = vetor[i] + vetor2[tamanhovet-1];
            printf("a soma das pontas é: %d \n ",vetpot[i]);
        
        
    }
    
       
    return 1;
}