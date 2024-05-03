#include<stdio.h>
#include<stdlib.h>
#include "game.h"

MAPA m;

void liberamapa(){
    int i;
    for(i = 0; i < m.linhas; i++){
        free(m.matriz[i]);
    }
    free(m.matriz);
}

void alocamapa(){
    int i;
    m.matriz = malloc(sizeof(char*) * m.linhas);
    for(i = 0 ; i < m.linhas ; i++){
        m.matriz[i] = malloc(sizeof(char)* (m.colunas+1));
    }
}

void lemapa(){
    FILE* f;
    int i;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("Erro na leitura\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

    alocamapa();
    
    for(i = 0; i < m.linhas; i++){
        fscanf(f, "%s", m.matriz[i]);
    }
    fclose(f);
}

void imprimemapa(){
        for(int i = 0; i < m.linhas; i++){
        printf("%s\n", m.matriz[i]);
        }
}

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;
    for(int i = 0; i < m.linhas; i++){
        for(int j = 0; j < m.colunas; j++){
            if(m.matriz[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }
    switch(direcao){
        case 'a':
            m.matriz[x][y-1] = '@';
            break;
        case 'w':
            m.matriz[x-1][y] = '@';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';            
    }

    m.matriz[x][y] = '.';
}


int main(){

   lemapa();
    
    do
    {
        imprimemapa();

        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while (!acabou());
    

    liberamapa();

    return 0;
}
