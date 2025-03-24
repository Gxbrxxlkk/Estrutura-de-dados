#include "tabeladisper.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    tabela_hash tabela;
    inicializar(&tabela);

    insereTabHash(&tabela, 15, 100);
    insereTabHash(&tabela, 25, 200); // Colide com 15 (15 % 10 == 25 % 10 == 5)
    insereTabHash(&tabela, 35, 300); // Colide novamente no índice 5
    insereTabHash(&tabela, 7, 50);   // Índice 7

    imprimeTabHash(&tabela);

    // Testando a busca
    printf("Buscar chave 25: %d\n", buscaTabHash(&tabela, 25)); // Esperado: 200
    printf("Buscar chave 7: %d\n", buscaTabHash(&tabela, 7));   // Esperado: 50
    printf("Buscar chave 10: %d\n", buscaTabHash(&tabela, 10)); // Esperado: -1 (não encontrado)

    // Testando a remoção
    printf("Remover chave 25: %d\n", removeTabHash(&tabela, 25)); // Esperado: 1 (sucesso)
    printf("Buscar chave 25 após remoção: %d\n", buscaTabHash(&tabela, 25)); // Esperado: -1

    imprimeTabHash(&tabela); // Mostra a tabela após a remoção

    return 0;
}