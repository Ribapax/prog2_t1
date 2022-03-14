#ifndef __ESTRUTURAS__
#define __ESTRUTURAS__

typedef struct EntradaSaida {
  char *entrada;
  char *saida;
  int mediana;
  int limiar;
  int angulo;
} EntradaSaida;

typedef struct Imagem {
  char P[3];
  int height, width, max;
  int **matriz;
} Imagem;

void iniciaEntradaSaida(EntradaSaida *teste);

int **alocarMatriz(int width, int height);

int liberarMatriz(int** arr, int height);


#endif