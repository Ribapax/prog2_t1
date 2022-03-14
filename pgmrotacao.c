#include "acessopgm.h"
#include "tratlcmd.h"
#include "acessoEstruturas.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

  Imagem image;
  EntradaSaida parametros;

  iniciaEntradaSaida(&parametros);

  lerParametros(argv, argc, &parametros);

  extDadosRotacao(parametros, &image);
  free(parametros.entrada);
  free(parametros.saida);
  return 0;
}