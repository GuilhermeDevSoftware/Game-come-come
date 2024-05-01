#include<stdio.h>
#include<stdlib.h>

char** mapa;
int linhas;
int colunas;

void liberamapa(){
    int i;
    for(i = 0; i < linhas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

void alocamapa(){
    int i;
    mapa = malloc(sizeof(char*) * linhas);
    for(i = 0 ; i < linhas ; i++){
        mapa[i] = malloc(sizeof(char)* (colunas+1));
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

    fscanf(f, "%d %d", &linhas, &colunas);

    alocamapa();
    
    for(i = 0; i < linhas; i++){
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

int main(){
    lemapa();
    
    mapa[0][0] = '|';
    mapa[4][9] = '@';

    int i;
    for(i = 0; i < linhas; i++){
        printf("%s\n", mapa[i]);
    }

    liberamapa();

    return 0;
}
