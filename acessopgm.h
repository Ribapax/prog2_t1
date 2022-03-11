#ifndef __ACESSO__
#define __ACESSO__

typedef struct imagem {
    char tipo[3];
    int largura;
    int altura;
    int maximo;
    int **matriz;
  } imagem;


void extDadosNega (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);

void extDadosLimiar (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr, int limiar);

void extDadosMedia (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);

void extDadosMediana (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr, int mediana);

void extDadosLbp (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);

void extDadosRotacao (char *arquivo, int *altura, int *largura, int * maximo, char **tipo,int**arr);


#endif