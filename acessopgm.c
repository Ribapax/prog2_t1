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
 
  // lê a primeira linha do arquivo para saber o tipo de imagem

  fgets (line, LINESIZE, arq) ;
  //*tipo = line;
  strcpy (*tipo, line);
  
  // le as linhas qcom as informa─oes de altura, largura e valor maximo
  // ignorando linhas de comentário 

  for (i=0; i<2; i++)
  {
    fgets (line, LINESIZE, arq);
    if(line[0]!= '#'){
      if(i == 0){
        char* token="";
        token = strtok(line, " ");
        *largura = atoi(token);
        token = strtok(NULL, " ");
        *altura = atoi(token);
      }
      else 
        *maximo = atoi(line);
    } 
    else
      i--;
  }
  
  fclose (arq) ;
}
