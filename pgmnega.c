//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include <stdio.h>

int main(int argc, char *argv[ ]){
	
  char *entrada="", *saida="";
  inOut(argv, argc, &entrada, &saida);
  
  printf("Okay. Entrada: %s e Saida: %s \n",entrada,saida);
  
  lerImg("Minha casinha");

  return 0;
}