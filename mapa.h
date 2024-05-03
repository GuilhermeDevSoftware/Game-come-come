typedef struct {
    char** matriz;
    int linhas;
    int colunas; 
}MAPA;

void liberamapa(MAPA * m);
void lemapa(MAPA * M);
void alocamapa(MAPA * M);
void imprimemapa(MAPA * M);