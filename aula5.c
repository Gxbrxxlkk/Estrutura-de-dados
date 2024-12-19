/*
UFMT - Universidade Federal de Mato Grosso
Estrutura de Dados I
Professor Ivairton
*/

#include <stdio.h>
#include <stdlib.h>
void preenchervet(int,int*);
int* copiavet(int*, int);

int main() {

    int *vetor, n, i, *pt;
    printf("Insira o tamanho do vetor desejado: ");
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));

    preenchervet(n, vetor);
    for (i=0; i <n ; i++) {
        printf("%d", vetor[i]);
    }
    pt = copiavet(vetor, n);
    for (i=0; i<n; i++) {
        if (i == 0){
        printf("Cópia vetor: \n");
    }   printf("%d", pt[i]);
    }

    return 0;
}

void preenchervet(int n ,int* vet) {
    int i;
    for (i=0; i < n; i++) {
        printf("Insira o %dº valor: \n", i+1);
        scanf("%d", &vet[i]);
    }
}

int* copiavet(int* vet, int tam_vet) {
    int *vetcopia, i;
    vetcopia = (int *)malloc(tam_vet* sizeof(int));
    for (i=0 ; i < tam_vet; i++) {
        vetcopia[i] = vet[i];
    }
    return vetcopia;
}