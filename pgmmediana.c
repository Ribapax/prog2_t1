//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	

  // Dados da linha de comando

  char *entrada = "", *saida = "";

  // Dados do tipo de imagem a ser filtrada

  
  int N;
  Imagem image;
  //int **arr;

  inOutMediana(argv, argc, &entrada, &saida,&N);

printf("teste0");
  // printf("Okay. Entrada: %s e Saida: %s \n",entrada,saida);

  /*Como sabemos que o tipo do arquivo só é ou P2 ou P5
    podemos definir o tamanho da nossa string como 3 char
  */

  extDadosMediana(entrada, &image,N);
  

  return 0;
}