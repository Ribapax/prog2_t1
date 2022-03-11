//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


  EntradaSaida parametros;

  Imagem image;

  iniciaEntradaSaida(&parametros);

  inOutTeste(argv, argc, &parametros);

  // printf("Okay. Entrada: %s e Saida: %s \n",entrada,saida);

  /*Como sabemos que o tipo do arquivo só é ou P2 ou P5
    podemos definir o tamanho da nossa string como 3 char
  */

  //extDadosNega(entrada, &height, &width, &max, &P, &arr);
  
  //extDadosNega(entrada,&image);


  return 0;
}