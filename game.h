void liberamapa();
void alocamapa();
void lemapa();

void move(char direcao);
int acabou();
void imprimemapa();

struct mapa {
    char** matriz;
    int linhas;
    int colunas; 
};

typedef struct mapa MAPA;