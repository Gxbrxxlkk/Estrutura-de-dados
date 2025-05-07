#ifndef __HEAD_ARBIN_H__
#define __HEAD_ARBIN_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no {
    int chave;
    void* dado;
    struct est_no* esq;
    struct est_no* dir;
};

typedef struct est_no tipo_no;

tipo_no* aloca_no(int, void*);
void insere_no(tipo_no**, int, void*);
void imprimie_pre_ordem(tipo_no*);
void imprime_em_ordem(tipo_no*);
void imprime_pos_ordem(tipo_no*);
int total_nos(tipo_no*);
int total_folhas(tipo_no*);
tipo_no* busca_no(tipo_no*, int);
int verifica_folha(tipo_no*, int);
int altura_arvore(tipo_no*);
void imprime_nivel(tipo_no*, int); //mais um parametro para um max nivel?
void imprime_arv_nivel(tipo_no*);
int contabiliza_no_nivel(tipo_no*, int);
void imprime_rota(tipo_no*, int);
tipo_no* busca_maior_no(tipo_no*);
tipo_no* busca_menor_no(tipo_no*);
tipo_no* remove_no(tipo_no*, int);

#endif