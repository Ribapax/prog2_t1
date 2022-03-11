#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "tratlcmd.h"

void iniciaEntradaSaida(EntradaSaida * teste){
  teste->entrada = "stdin";
  teste->saida = "stdout";
  teste->limiar = 50;
  teste->angulo = 90;
  teste->mediana = 3;
}

void inOutTeste(char *argv[], int argc, EntradaSaida * teste) {
  for (int c = 1; c < argc; c ++) {
    printf("%d : %s",c,argv[c]);
  }
  printf("%s\n",teste->entrada);
  printf("%s\n",teste->entrada);
  printf("%d\n",teste->limiar);
  printf("%d\n",teste->angulo);
  printf("%d\n",teste->mediana);

}



void inOutNega(char *argv[], int argc, char **in, char **out) {
  for (int c = 1; c < argc; c += 2) {

    if (strcmp(argv[c], "-i") == 0)
      *in = argv[c + 1];
    if (strcmp(argv[c], "-o") == 0)
      *out = argv[c + 1];
  }
}

void inOutLbp(char *argv[], int argc, char **in, char **out) {
  for (int c = 1; c < argc; c += 2) {

    if (strcmp(argv[c], "-i") == 0)
      *in = argv[c + 1];
    if (strcmp(argv[c], "-o") == 0)
      *out = argv[c + 1];
  }
}

void inOutRotacao(char *argv[], int argc, char **in, char **out, int *N) {
  for (int c = 1; c < argc; c += 2) {

    if (strcmp(argv[c], "-i") == 0)
      *in = argv[c + 1];
    if (strcmp(argv[c], "-o") == 0)
      *out = argv[c + 1];
  }
}

void inOutMedia(char *argv[], int argc, char **in, char **out) {
  for (int c = 1; c < argc; c += 2) {

    if (strcmp(argv[c], "-i") == 0)
      *in = argv[c + 1];
    if (strcmp(argv[c], "-o") == 0)
      *out = argv[c + 1];
  }
}

void inOutMediana(char *argv[], int argc, char **in, char **out,int *N) {
  
  for (int c = 1; c < argc; c += 2) {
    if (strcmp(argv[c], "-i") == 0)
      *in = argv[c + 1];
    if (strcmp(argv[c], "-o") == 0)
      *out = argv[c + 1];
    if (strcmp(argv[c], "-m") == 0)
      *N = atoi(argv[c + 1]);
  }
}

void inOutLimiar(char *argv[], int argc, char **in, char **out, int *N) {
  for (int c = 1; c < argc; c += 2) {
    if (strcmp(argv[c], "-i") == 0)
      *in = argv[c + 1];
    if (strcmp(argv[c], "-o") == 0)
      *out = argv[c + 1];
    if (strcmp(argv[c], "-l") == 0)
      *N = atoi(argv[c + 1]);
  }
}
