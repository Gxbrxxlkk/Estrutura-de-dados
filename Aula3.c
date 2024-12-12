/*
UFMT - Universidade Federal de Mato Grosso
Professor Ivairton
Estrutura de dados I
*/

#include <stdio.h>
#include <stdlib.h>



struct stc_produto {

    int codigo;
    float preco_custo;
    float preco_venda;

};


typedef struct stc_produto tipo_produto;
#define const 3
#define TAM_VENDA 2


struct venda
{
    tipo_produto produtos[TAM_VENDA];
    int qtd_produtos[TAM_VENDA];
    int total, subtotal;


};
typedef struct venda tipo_venda;


int main() {

    tipo_produto vet_produtos[const];
    int lucro, j, i;
    tipo_venda reg_venda;

    for (i=0; i<const; i++) {

    printf("Informe o codigo do produto %d:", i);
    scanf("%d", &vet_produtos[i].codigo);
    printf("Informe o preco de custo: ");
    scanf("%f", &vet_produtos[i].preco_custo);

    printf("Informe o lucro: ");
    scanf("%d", &lucro);
    // Calcula o preco de venda de cada produto
    vet_produtos[i].preco_venda = vet_produtos[i].preco_custo + (vet_produtos[i].preco_custo * (float)lucro/100);

    }
    for (i = 0; i < const; i++)   {
        
        printf("Produto %d:\n Codigo: %d\n Preco de custo: %f\n Preco de venda: %f", i+1, vet_produtos[i].codigo,vet_produtos[i].preco_custo,vet_produtos[i].preco_venda);
    }
    printf("Informe os produtos comprados: ");
    for (i = 0; i < TAM_VENDA; i++)
    {
        printf("Informe o código do produto %d: ", i+1);
        scanf("%d", &reg_venda.produtos[i]);
        printf("\tInforme a quantidade: ");
        scanf("%d", &reg_venda.qtd_produtos[i]);
        while (j)
        {
        
        }
        

    }
    





    return 0;
}