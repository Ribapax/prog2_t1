//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  Imagem image;
  char *entrada = "", *saida = "";

  int N;
  // Dados da linha de comando


  // Dados do tipo de imagem a ser filtrada

  inOutLimiar(argv, argc, &entrada, &saida, &N);

  extDadosLimiar(entrada, &image, N);

  return 0;
}