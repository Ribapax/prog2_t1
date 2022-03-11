#ifndef __TRATAMENTO__
#define __TRATAMENTO__

typedef struct EntradaSaida{
    char *entrada;
    char *saida;
    int mediana ;
    int limiar  ;
    int angulo ;
} EntradaSaida;


void iniciaEntradaSaida(EntradaSaida * teste);

void inOutNega (char *argv[ ], int argc,char **in,char **out );

void inOutTeste (char *argv[ ],int argc, EntradaSaida * teste );

void inOutLbp (char *argv[ ], int argc,char **in,char **out );

void inOutRotacao (char *argv[ ], int argc,char **in,char **out , int *N);

void inOutMedia (char *argv[ ], int argc,char **in,char **out );

void inOutMediana (char *argv[ ], int argc,char **in,char **out , int* N);

void inOutLimiar (char *argv[ ], int argc,char **in,char **out , int* N);
  
#endif