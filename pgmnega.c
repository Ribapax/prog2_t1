//#include "teste.h"
#include "acessoEstruturas.h"
#include "acessopgm.h"
#include "tratlcmd.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  EntradaSaida parametros;

  Imagem image;

  iniciaEntradaSaida(&parametros);

  lerParametros(argv, argc, &parametros);

  extDadosNega(parametros, &image);

  if (strcmp(parametros.entrada, "") != 0)
    free(parametros.entrada);
  if (strcmp(parametros.saida, "") != 0)
    free(parametros.saida);
  
  return 0;
}