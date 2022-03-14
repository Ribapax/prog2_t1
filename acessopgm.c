#include "acessopgm.h"
#include "acessoEstruturas.h"
#include "tratlcmd.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINESIZE 1024


int qsortComparador(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

//Escreve a imagem, dependendo do formato informado na struct


void escreveImg(Imagem *img, char *saida) {
  FILE *arq = stdout;
  // int i;
  //  abre o arquivo em leitura
  if (strlen(saida) != 0)
    arq = fopen(saida, "w");

  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  unsigned char byte_value;

  fprintf(arq, "%s", img->P);
  fprintf(arq, "%d %d\n", img->width, img->height);
  fprintf(arq, "%d\n", img->max);
  if (img->P[1] == '2') {
    for (int i = 0; i < img->height; i++) {
      for (int j = 0; j < img->width; j++) {
        fprintf(arq, "%d ", img->matriz[i][j]);
      }
      fprintf(arq, "\n");
    }
  } else {
    for (int i = 0; i < img->height; i++) {
      for (int j = 0; j < img->width; j++) {
        byte_value = img->matriz[i][j];
        fwrite(&byte_value, sizeof(char), 1, arq);
      }
    }
  }

  fclose(arq);
}
//Le a imagem, dependendo do valor do char* entrada escolhe se a leitura é de arquivo ou de stdin
void leImg(Imagem *img, char *entrada) {

  FILE *arq = stdin;
  if (strlen(entrada) != 0)
    arq = fopen(entrada, "r");

  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  char line[LINESIZE + 1];

  fgets(line, LINESIZE, arq);
  strcpy(img->P, line);

  for (int i = 0; i < 2; i++) {
    fgets(line, LINESIZE, arq);
    if (line[0] != '#') {
      if (i == 0) {
        char *token = "";
        token = strtok(line, " ");
        img->width = atoi(token);
        token = strtok(NULL, " ");
        img->height = atoi(token);
      } else
        img->max = atoi(line);
    } else
      i--;
  }
  int num_value;
  unsigned char byte_value;
  img->matriz = alocarMatriz(img->width, img->height);

  if (img->P[1] == '2') {
    for (int i = 0; i < img->height; i++) {
      for (int j = 0; j < img->width; j++) {
        fscanf(arq, "%d", &num_value);
        img->matriz[i][j] = num_value;
      }
    }
  } else {
    for (int i = 0; i < img->height; i++) {
      for (int j = 0; j < img->width; j++) {
        fread(&byte_value, sizeof(char), 1, arq);
        img->matriz[i][j] = byte_value;
      }
    }
  }
  fclose(arq);
}


void extDadosNega(EntradaSaida parametros, Imagem *img) {

  leImg(img, parametros.entrada);

  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      img->matriz[i][j] = img->max - img->matriz[i][j];
    }
  }

  escreveImg(img, parametros.saida);
  liberarMatriz(img->matriz, img->height);

}

void extDadosLimiar(EntradaSaida parametros, Imagem *img) {

  leImg(img, parametros.entrada);

  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      if (img->matriz[i][j] >= img->max * parametros.limiar / 100)
        img->matriz[i][j] = img->max;
      else
        img->matriz[i][j] = 0;
    }
  }

  escreveImg(img, parametros.saida);
  liberarMatriz(img->matriz, img->height);
}

void extDadosMedia(EntradaSaida parametros, Imagem *img) {

  leImg(img, parametros.entrada);

  Imagem imgAux;

  strcpy(imgAux.P, img->P);
  imgAux.width = img->width;
  imgAux.height = img->height;
  imgAux.max = img->max;
  imgAux.matriz = alocarMatriz(imgAux.width, imgAux.height);

  int soma = 0;
  int n = 0;

  for (int i = 0; i < imgAux.height; i++) {
    for (int j = 0; j < imgAux.width; j++) {
      n = 0;
      soma = 0;
      for (int c = i - 1; c <= i + 1; c++) {
        for (int k = j - 1; k <= j + 1; k++) {
          if (c >= 0 && c < imgAux.height && k >= 0 && k < imgAux.width) {
            soma = img->matriz[c][k] + soma;
            n++;
          }
        }
      }
      imgAux.matriz[i][j] = soma / n;
    }
  }

  escreveImg(&imgAux, parametros.saida);
  liberarMatriz(imgAux.matriz, imgAux.height);
  liberarMatriz(img->matriz, imgAux.height);
}

void extDadosMediana(EntradaSaida parametros, Imagem *img) {

  leImg(img, parametros.entrada);

  int index = parametros.mediana*parametros.mediana;
  int range[index];
  int offset = (parametros.mediana/ 2);

  Imagem imgAux;

  strcpy(imgAux.P, img->P);
  imgAux.width = img->width;
  imgAux.height = img->height;
  imgAux.max = img->max;
  imgAux.matriz = alocarMatriz(imgAux.width, imgAux.height);

  int n = 0;

  for (int i = 0; i < imgAux.height; i++) {
    for (int j = 0; j < imgAux.width; j++) {
      //condição para garantir que ao percorrer a imagem, a mascara sempre esteja dentro do dominio da matriz, sem correr risco de seg fault
      if (i < offset || i >= imgAux.height - offset || j < offset || j >= imgAux.width - offset) {
        imgAux.matriz[i][j] = img->matriz[i][j];
      } else {
        n=0;
        for (int c = i - offset; c <= i + offset; c++) {
          for (int k = j - offset; k <= j + offset; k++) {
            range[n]=img->matriz[c][k];
            n++;
          }
        }
        qsort(range,index, sizeof(int),qsortComparador);
        imgAux.matriz[i][j] = range[index/2]; 
      }
    }
  } 
 
  escreveImg(&imgAux, parametros.saida);
  liberarMatriz(imgAux.matriz, imgAux.height);
  liberarMatriz(img->matriz, imgAux.height);
}

void extDadosLbp(EntradaSaida parametros, Imagem *img) {

  leImg(img, parametros.entrada);

  Imagem imgAux;

  strcpy(imgAux.P, img->P);
  imgAux.width = img->width;
  imgAux.height = img->height;
  imgAux.max = img->max;
  imgAux.matriz = alocarMatriz(imgAux.width, imgAux.height);

  int soma, n;

  for (int i = 0; i < imgAux.height; i++) {
    for (int j = 0; j < imgAux.width; j++) {
      n = 0;
      soma = 0;
      for (int c = i - 1; c <= i + 1; c++) {
        for (int k = j - 1; k <= j + 1; k++) {
          //checa para ver a vizinhança pertence a matriz ao mesmo tempo que soma o termo n para que quando possivel sai o resultado em 2 laços somente
          if (c >= 0 && c < imgAux.height && k >= 0 && k < imgAux.width) {

            if (c != i || k != j) {
              if (img->matriz[c][k] >= img->matriz[i][j]) {

                soma = soma + pow(2, n);
              }
            } else {
              n--;
            }
          }
          n++;
        }
      }
      imgAux.matriz[i][j] = soma;
    }
  }

  escreveImg(&imgAux, parametros.saida);
  liberarMatriz(imgAux.matriz, imgAux.height);
  liberarMatriz(img->matriz, imgAux.height);
}

void extDadosRotacao(EntradaSaida parametros, Imagem *img) {
  //Rotação simples de imagem, pega a imagem e devolve ela rotacionando de 90 graus
  //A formula apresentada dentro do for foi tirada de observação de outras matrizes
  leImg(img, parametros.entrada);
  Imagem imgAux;

  if (parametros.angulo == 90) {

    strcpy(imgAux.P, img->P);
    imgAux.width = img->height;
    imgAux.height = img->width;
    imgAux.max = img->max;
    imgAux.matriz = alocarMatriz(img->height, img->width);

    for (int i = 0; i <= img->width - 1; i++) {
      for (int j = 0; j <= img->height - 1; j++) {

        imgAux.matriz[i][j] = img->matriz[(img->height - 1) - j][i];
      }
    }
  }

  escreveImg(&imgAux, parametros.saida);
  liberarMatriz(imgAux.matriz, imgAux.height);
  liberarMatriz(img->matriz, imgAux.height);
}
