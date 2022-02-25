#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINESIZE 1024



void extDados (char *arquivo, int *altura, int *largura, int * maximo, char **tipo)
{
  FILE *arq;
  int i ;
  char line[LINESIZE+1] ;
 
  // abre o arquivo em leitura
  arq = fopen (arquivo, "r") ;
  if ( ! arq )
  {
    perror ("Erro ao abrir arquivo") ;
    exit (1) ;
  }
  printf ("Okay\n") ;
 
  // lê as 10 primeiras linhas do arquivo
  fgets (line, LINESIZE, arq) ;
  *tipo = line;
  printf ("%s \n", *tipo);
  
  for (i=0; i<4; i++)
  {
    fgets (line, LINESIZE, arq) ;
    printf ("%d: %c", i, line[0]) ;
  }
 
  // fecha o arquivo
  fclose (arq) ;
  printf ("%s", arquivo) ;
}
