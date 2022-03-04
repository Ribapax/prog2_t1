//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[ ]){
	

  // Dados da linha de comando

  char *entrada="", *saida="";
  
  //Dados do tipo de imagem a ser filtrada

  char *P;
  int height, width, max;

  inOut(argv, argc, &entrada, &saida);
  
  //printf("Okay. Entrada: %s e Saida: %s \n",entrada,saida);
  
  /*Como sabemos que o tipo do arquivo só é ou P2 ou P5
    podemos definir o tamanho da nossa string como 3 char
  */
  P = calloc(3,sizeof(char));

  extDados(entrada,&height, &width, &max, &P);


  printf("altura: %d\n",height);
  printf("largura: %d\n",width);
  printf("valor maximo: %d\n",max);
  printf("tipo: %s\n",P);


  return 0;
}