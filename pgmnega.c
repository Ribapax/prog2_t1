//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include <stdio.h>

int main(int argc, char *argv[ ]){
	

  // Dados da linha de comando

  char *entrada="", *saida="";
  
  //Dados do tipo de imagem a ser filtrada

  char *P="      ";
  int height, width, max;

  
  
  inOut(argv, argc, &entrada, &saida);
  
  //printf("Okay. Entrada: %s e Saida: %s \n",entrada,saida);
  
  extDados(entrada,&height, &width, &max, &P);

  return 0;
}