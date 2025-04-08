#ifndef __COVID_H__
#define __COVID_H__

#include <stdlib.h>

struct no_lista {
    char pais/regiao[100];
    int confirmados;
    int mortes;
    int recuperados;
    int ativos;
    int novos_casos;
    int novas_mortes;
    int novos_recuperados;
    float mortes_por_casos;
    float recuperados_por_casos;
    float mortes_por_recuperados
    int confirmados_ultima_semana;
    int mudancas_uma_semana;
    float porcentagem_semana;
    char regiao [100];
    struct no_lista* prox;
}
typedef no_lista tipo_lista;

void ler_dados();
tipo_lista* aloca_no(tipo_lista);

#endif