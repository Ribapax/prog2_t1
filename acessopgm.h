#ifndef __ACESSO__
#define __ACESSO__

typedef struct Imagem {
    char P[3];
    int height, width, max;
    int **matriz;
  } Imagem;


//void extDadosNega (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);

void extDadosNega (char *arquivo,Imagem *img);

void extDadosLimiar (char *arquivo,Imagem *img, int limiar);

void extDadosMedia (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);

void extDadosMediana (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr, int mediana);

void extDadosLbp (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);

void extDadosRotacao (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);


#endif