#include <stdio.h>
#include "tratlcmd.h"
#include <stdlib.h>
#include <string.h>


void lerParametros(char *argv[], int argc, EntradaSaida *parametros) {
  for (int c = 1; c < argc; c += 2) {
    if (argv[c][1] == 'i') {
      parametros->entrada = malloc((strlen(argv[c+1])) * sizeof(char));
      strcpy(parametros->entrada, argv[c + 1]);
      
    }
    if (strcmp(argv[c], "-o") == 0) {
      parametros->saida = malloc((strlen(argv[c+1])) * sizeof(char));
      strcpy(parametros->saida, argv[c + 1]);
    }
    if (strcmp(argv[c], "-m") == 0)
      parametros->mediana =  atoi(argv[c + 1]);
    if (strcmp(argv[c], "-l") == 0)
      parametros->limiar =  atoi(argv[c + 1]);
    if (strcmp(argv[c], "-a") == 0)
      parametros->angulo =  atoi(argv[c + 1]);
  }
}

