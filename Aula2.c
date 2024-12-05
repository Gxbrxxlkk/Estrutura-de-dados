/*** 
 * UFMT - Universidade Federal de Mato Grosso
 * Estrutura de dados I
 * Professor Ivairton
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade;
    printf("Informe sua idade: ");
    scanf("%d", &idade);
    if (idade >= 18) {
        printf("Você é maior de idade. \n");
    } else {
        printf("Você é menor de idade. \n");
    }
    printf("Vamos fazer uma contagem agora\n");
    int contador;

    contador = 1;
    while (contador <= 5) {
        printf("Contando... %d\n", contador);
        //contador += 2; O ++ sempre vai aumentar uma unidade, quando for aumentar ou decrementar mais de uma unidade, usar esse
        contador ++;
    }
    
    for ( ; contador >= 0; contador--) {
        printf("Contando... %d\n", contador);
    } 

    int voto;
    voto = 1;
    switch (voto) {
    case 1:
        printf("Voce votou em 1");
        break;
    case 2:
        printf("Voce votou em 2");
        break;
    case 3:
        printf("Voce votou em 3");
        break;
    default:
        printf("Voce votou nulo");
        break;
    }

 //   printf("Imprimindo com o while\n");
   // contador = 5;
  //  do {
   //     printf("Contando... %d\n", contador);
   //     
   // } while (/* condition */);
    


    return 0;
}