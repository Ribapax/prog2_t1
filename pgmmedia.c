//#include "teste.h"
#include "acessopgm.h"
#include "tratlcmd.h"
#include "acessoEstruturas.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  EntradaSaida parametros;

  iniciaEntradaSaida(&parametros);

  Imagem image;

  lerParametros(argv, argc, &parametros);


  extDadosMedia(parametros, &image);
  free(parametros.entrada);
  free(parametros.saida);
  return 0;
}