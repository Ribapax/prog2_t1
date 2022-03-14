#include "acessoEstruturas.h"
#include <stdlib.h>
#include <stdio.h>

void iniciaEntradaSaida(EntradaSaida *teste) {
  teste->entrada = "";
  teste->saida = "";
  teste->limiar = 50;
  teste->angulo = 90;
  teste->mediana = 3;
}

int **alocarMatriz(int width, int height) {
  int **arr;
  arr = malloc(height * sizeof(int *));
  if (arr == NULL) {
    perror("Memoria insuficiente");
    exit(1);
  }
  for (int i = 0; i < height; i++) {
    arr[i] = malloc(width * sizeof(int));
    if (arr[i] == NULL) {
      perror("Memoria insuficiente");
      exit(1);
    }
  }
  return arr;
}

int liberarMatriz(int** arr, int height){
	for(int i = 0; i < height; i++)
		free(arr[i]);
	free(arr);
	return 1;
}


