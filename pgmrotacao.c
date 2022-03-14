#include "acessopgm.h"
#include "tratlcmd.h"
#include "acessoEstruturas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

  Imagem image;
  EntradaSaida parametros;

  iniciaEntradaSaida(&parametros);

  lerParametros(argv, argc, &parametros);

  extDadosRotacao(parametros, &image);
  
  if (strcmp(parametros.entrada, "") != 0)
    free(parametros.entrada);
  if (strcmp(parametros.saida, "") != 0)
    free(parametros.saida);
  return 0;
}