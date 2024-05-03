#include<stdio.h>
#include<stdlib.h>
#include "mapa.h"

void encontramapa(MAPA * m, POSICAO * p, char c){
        for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void liberamapa(MAPA* m){
    int i;
    for(i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void alocamapa(MAPA* m){
    int i;
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(i = 0 ; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char)* (m->colunas+1));
    }
}

void lemapa(MAPA* m){
    FILE* f;
    int i;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Erro na leitura\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocamapa(m);
    
    for(i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void imprimemapa(MAPA* m){
        for(int i = 0; i < m->linhas; i++){
        printf("%s\n", m->matriz[i]);
        }
}