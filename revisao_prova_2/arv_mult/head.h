#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdlib.h>
#include <stdio.h>

#define MAX 3

struct est_no  
{
    int chave[MAX];
    void* dado[MAX];
    struct est_no* filhos[MAX + 1];
    int tamanho;
};
typedef struct est_no tipo_no;

#endif

//prototipo das funçopes

tipo_no* aloca_no(void* dado, int chave);
void inserir_no(tipo_no**, void*, int);
void imprime_pre_ordem(tipo_no *no);
void imprime_pos_ordem(tipo_no *no);
void imprime_em_ordem(tipo_no *no);
tipo_no* busca_no(tipo_no*, int);
int total_nos(tipo_no*);
int total_folhas(tipo_no*);
int verifica_folha(tipo_no *no, int chave);
int altura_arvore(tipo_no *no);
int busca_maior(tipo_no *no);
int busca_menor(tipo_no *no);
void imprime_nivel(tipo_no *no, int nivel);
void imprime_arv_nivel(tipo_no *no);
int contabiliza_no_por_nivel(tipo_no *no, int nivel);
void imprime_rota(tipo_no *no, int chave);
tipo_no *remove_no(tipo_no *no, int chave);
