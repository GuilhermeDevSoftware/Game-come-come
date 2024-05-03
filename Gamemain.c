#include<stdio.h>
#include<stdlib.h>
#include "game.h"
#include"mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

int ehdirecao(char direcao){
        direcao == 'a' ||
        direcao == 'w' ||
        direcao == 's' ||
        direcao == 'd';
}

void move(char direcao){

    if(!ehdirecao(direcao)) return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao){
  
        case 'a':
            proximoy--;
            break;
        case 'w':
            proximox--;
            break;
        case 's':
            proximox++;
            break;
        case 'd':
            proximoy++; 
            break;      
    }   

    if(!ehvalida(&m, proximox, proximoy))
    return;

    if(!ehvazia(&m, proximox, proximoy))
    return;

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}


int main(){

   lemapa(&m);
   encontramapa(&m, &heroi, '@');
    
    do
    {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while (!acabou());
    

    liberamapa(&m);

    return 0;
}
