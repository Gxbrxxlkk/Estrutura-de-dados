 #include "head.h"

int main() {
    tipo_no* raiz = NULL;

    // Inserindo alguns nós na árvore
    int dado1 = 10, dado2 = 20, dado3 = 15, dado4 = 25, dado5 = 5, dado6 = 30;
    inserir_no(&raiz, &dado1, 10);
    inserir_no(&raiz, &dado2, 20);
    inserir_no(&raiz, &dado3, 15);
    inserir_no(&raiz, &dado4, 25);
    inserir_no(&raiz, &dado5, 5);
    inserir_no(&raiz, &dado6, 30);

    // Testando as funções de impressão
    printf("Impressão em pré-ordem:\n");
    imprime_pre_ordem(raiz);
    printf("\n\n");

    printf("Impressão em pós-ordem:\n");
    imprime_pos_ordem(raiz);
    printf("\n\n");

    printf("Impressão em ordem:\n");
    imprime_em_ordem(raiz);
    printf("\n\n");

    printf("Impressão por nível:\n");
    imprime_arv_nivel(raiz);
    printf("\n");

    // Testando busca
    int chave_busca = 15;
    tipo_no* encontrado = busca_no(raiz, chave_busca);
    if (encontrado != NULL) {
        printf("Chave %d encontrada na árvore.\n", chave_busca);
    } else {
        printf("Chave %d não encontrada na árvore.\n", chave_busca);
    }

    // Testando total de nós e folhas
    printf("Total de nós na árvore: %d\n", total_nos(raiz));
    printf("Total de folhas na árvore: %d\n", total_folhas(raiz));

    // Testando altura da árvore
    printf("Altura da árvore: %d\n", altura_arvore(raiz));

    // Testando busca do maior e menor valor
    printf("Maior valor na árvore: %d\n", busca_maior(raiz));
    printf("Menor valor na árvore: %d\n", busca_menor(raiz));

    // Testando impressão de rota
    printf("Rota para a chave 25:\n");
    imprime_rota(raiz, 25);
    printf("\n");

    // Testando contabilização de nós por nível
    int nivel = 1;
    printf("Total de nós no nível %d: %d\n", nivel, contabiliza_no_por_nivel(raiz, nivel));

    return 0;
}