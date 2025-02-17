/**
 * Pilha (alocação dinâmica)
 * Empilha/desempilha ocorre pela ponta(inicio)
 * ponteiro auxiliar. utilizar free e maloc para criar e remover nós
 * 
 * 
 * Empilha
 * verifica se a 'pilha' está vazia
 *  se sim, aloca novo nó e atualiza 'pilha'
 * senão, aloca novo nó, atualiza o proximo dele para apontar para ele
 * 
 * Desempilha
 *  verifica se a pilha tem valor
 * se sim, guarda valor do topo, usa um ponteiro aux p/ apontar o topo, atualiza 'pilha' para o segundo nó
 * libera da memória o nó auxiliar, retorna o valor...
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 typedef struct no {
     int dado;
     struct no* proximo; 
 } no;
 
 typedef struct {
     no* topo;
 } Pilha;
 
 Pilha* criarPilha() {
     Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
     if (pilha == NULL) {
         printf("Erro ao alocar memória para a pilha.\n");
         exit(EXIT_FAILURE);
     }
     pilha->topo = NULL;
     return pilha;
 }
 
 int estaVazia(Pilha* pilha) {
     return pilha->topo == NULL;
 }
 
 void empilhar(Pilha* pilha, int valor) {
     no* novo_no = (no*)malloc(sizeof(no));
     if (novo_no == NULL) {
         printf("erro ao alocar memória para novo nó.\n");
         exit(EXIT_FAILURE);
     }
     novo_no->dado = valor;
     novo_no->proximo = pilha->topo;
     pilha->topo = novo_no;
 }
 
 int desempilhar(Pilha* pilha) {
     if (estaVazia(pilha)) {
         printf("A pilha está vazia\n");
         exit(EXIT_FAILURE);
     }
     no* temp = pilha->topo;
     int valor = temp->dado;
     pilha->topo = temp->proximo;
     free(temp);
     return valor;
 }
 
 int topo(Pilha* pilha) {
     if (estaVazia(pilha)) {
         printf("Está vazia!\n");
         exit(EXIT_FAILURE);
     }
     return pilha->topo->dado;
 }
 
 void liberarPilha(Pilha* pilha) {
     while (!estaVazia(pilha)) {
         desempilhar(pilha);
     }
     free(pilha);
 }
 
 int main() {
     Pilha* pilha = criarPilha();
 
     empilhar(pilha, 10);
     empilhar(pilha, 20);
     empilhar(pilha, 30);
 
     printf("Topo da pilha: %d\n", topo(pilha));
 
     printf("Desempilhando: %d\n", desempilhar(pilha));
     printf("Desempilhando: %d\n", desempilhar(pilha));
 
     printf("Topo da pilha: %d\n", topo(pilha));
 
     liberarPilha(pilha);
     return 0;
 }
 