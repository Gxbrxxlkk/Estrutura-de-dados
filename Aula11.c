/**
 * Lista encadeada
 * Inserção:
 * Inicio
 * Por posição
 * Fim
 * 
 * Remoção
 * Inicio
 * Fim
 * Por posição
 * Por valor
 * 
 * Busca
 * Por valor
 * Por posição
 * Contagem de elementos
 *  **ptr \/
 *  *Lista =  Null
 *  Cria e aloca um nó, inicializando o ponteiro dele como nulo (usar ponteiro auxiliar para passar pelos nós)
 * Inserção por possição(&lista, k, i) verificar se a lista está vazia, (usar uma variavel para guardar posição),  caso for inserido uma posição inválida(Maior que a lista) não executar a ação
 * usar aux_prox? 
 */


 #include <stdio.h>
 #include <stdlib.h>
 
 // Definição do nó
 typedef struct Node {
     int data;
     struct Node *next;
 } Node;
 
 Node* inserirNoInicio(Node *head, int valor) {
     Node *novoNo = (Node*) malloc(sizeof(Node));
     if (novoNo == NULL) {
         printf("Erro ao alocar memória!\n");
         return head;
     }
     novoNo->data = valor;
     novoNo->next = head;
     return novoNo;
 }
 
 Node* inserirNoFinal(Node *head, int valor) {
     Node *novoNo = (Node*) malloc(sizeof(Node));
     if (novoNo == NULL) {
         printf("Erro ao alocar memória!\n");
         return head;
     }
     novoNo->data = valor;
     novoNo->next = NULL;
     if (head == NULL) {
         return novoNo;
     }
     Node *temp = head;
     while (temp->next != NULL) {
         temp = temp->next;
     }
     temp->next = novoNo;
     return head;
 }
 
 void exibirLista(Node *head) {
     Node *temp = head;
     while (temp != NULL) {
         printf("%d -> ", temp->data);
         temp = temp->next;
     }
     printf("NULL\n");
 }
 
 Node* removerNo(Node *head, int valor) {
     if (head == NULL) {
         printf("Lista vazia!\n");
         return NULL;
     }
     Node *temp = head, *anterior = NULL;
     if (temp != NULL && temp->data == valor) {
         head = temp->next;
         free(temp);
         return head;
     }
     while (temp != NULL && temp->data != valor) {
         anterior = temp;
         temp = temp->next;
     }
     if (temp == NULL) {
         printf("Valor não encontrado!\n");
         return head;
     }
     anterior->next = temp->next;
     free(temp);
     return head;
 }
 
 void liberarLista(Node *head) {
     Node *temp;
     while (head != NULL) {
         temp = head;
         head = head->next;
         free(temp);
     }
 }
 
 int main() {
     Node *head = NULL;
 
     head = inserirNoInicio(head, 10);
     head = inserirNoInicio(head, 20);
     head = inserirNoInicio(head, 30);
     printf("Lista após inserções no início: ");
     exibirLista(head);
 
     head = inserirNoFinal(head, 40);
     head = inserirNoFinal(head, 50);
     printf("Lista após inserções no final: ");
     exibirLista(head);
 
     head = removerNo(head, 20);
     printf("Lista após remover 20: ");
     exibirLista(head);
 
     liberarLista(head);
     return 0;
 }
 
