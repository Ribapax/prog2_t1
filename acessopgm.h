#ifndef __ACESSO__
#define __ACESSO__

#include "acessoEstruturas.h"


// void extDadosNega (char *arquivo, int *altura, int *largura, int * maximo,
// char **tipo,int**arr);

void escreveImg(Imagem *img, char *saida);

void leImg(Imagem *img, char *entrada);

void extDadosNega(EntradaSaida parametros, Imagem *img);

void extDadosLimiar(EntradaSaida parametros, Imagem *img) ;

void extDadosMedia(EntradaSaida parametros, Imagem *img);

void extDadosMediana(EntradaSaida parametros, Imagem *img);

void extDadosLbp(EntradaSaida parametros, Imagem *img) ;

void extDadosRotacao(EntradaSaida parametros, Imagem *img) ;

#endif