#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
typedef struct {
    char** matriz;
    int linhas;
    int colunas; 
}MAPA;

typedef struct{
    int x;
    int y;
}POSICAO;

void liberamapa(MAPA * m);
void lemapa(MAPA * M);
void alocamapa(MAPA * M);
void imprimemapa(MAPA * M);
void encontramapa(MAPA * m, POSICAO * p, char c);

int ehvalida(MAPA * m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, 
    int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);    
