//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	

  // Dados da linha de comando

  char *entrada = "", *saida = "";
  Imagem image;

  // Dados do tipo de imagem a ser filtrada
  
  //int **arr;

  inOutMedia(argv, argc, &entrada, &saida);

  // printf("Okay. Entrada: %s e Saida: %s \n",entrada,saida);

  /*Como sabemos que o tipo do arquivo só é ou P2 ou P5
    podemos definir o tamanho da nossa string como 3 char
  */
 

  extDadosMedia(entrada, &image);
  

  return 0;
}