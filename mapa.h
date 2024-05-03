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
