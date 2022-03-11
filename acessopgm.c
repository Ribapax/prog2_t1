#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acessopgm.h"
#define LINESIZE 1024


int **arrAlloc(int width, int height) {
  int **arr;
  arr = malloc(height * sizeof(int *));
  if (arr == NULL) {
    perror("Memoria insuficiente");
    exit(1);
  }
  for (int i = 0; i < height; i++) {
    arr[i] = malloc(width * sizeof(int));
    if (arr[i] == NULL) {
      perror("Memoria insuficiente");
      exit(1);
    }
  }
  return arr;
}

void initializeArr(int **arr, int width, int height) {
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      arr[i][j] = 0;
}

void escreveImg(){
  
}

void leImg(FILE *arq,Imagem *img){

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
  img->matriz = arrAlloc(img->width, img->height);
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

}

void extDadosNega(char *arquivo, Imagem * img) {
  FILE *arq;
  //int i;
  // abre o arquivo em leitura
  arq = fopen(arquivo, "r");
  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  leImg(arq,img);
  fclose(arq);
  
  printf("%s", img->P);
  printf("%d %d\n", img->width, img->height);
  printf("%d\n", img->max);

  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      printf("%d ", img->max - img->matriz[i][j]);
    }
    printf("\n");
  }

}

void extDadosLimiar(char *arquivo, Imagem * img, int limiar) {
  FILE *arq;

  // abre o arquivo em leitura
  arq = fopen(arquivo, "r");
  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  leImg(arq,img);

  printf("%s", img->P);
  printf("%d %d\n", img->width, img->height);
  printf("%d\n", img->max);

  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      if (img->matriz[i][j] >= img->max * limiar / 100)
        printf("%d ", img->max);
      else
        printf("%d ", 0);
    }
    printf("\n");
  }

  fclose(arq);
}

void extDadosMedia(char *arquivo, Imagem *img) {
  FILE *arq;
  int i;
  char line[LINESIZE + 1];
  

  // abre o arquivo em leitura
  arq = fopen(arquivo, "r");
  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  // lê a primeira linha do arquivo para saber o tipo de imagem

  fgets(line, LINESIZE, arq);
  strcpy(img->P, line);

  // le as linhas qcom as informa─oes de altura, largura e valor maximo
  // ignorando linhas de comentário

  for (i = 0; i < 2; i++) {
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
  img->matriz = arrAlloc(img->width + 2, img->height + 2);
  initializeArr(img->matriz, img->width + 2, img->height + 2);
  // printf("teste");
  //  printf("testeokay");
  //  printf("\n%d\n", strncmp(img->P, "P2", 2));
  if (strncmp(img->P, "P2", 2) == 0) {
    for (int i = 0; i < img->height + 2; i++) {
      for (int j = 0; j < img->width + 2; j++) {
        if (i == 0 || i == img->height - 1)
          img->matriz[i][j] = -1;
        else if (j == 0 || j == img->width - 1)
          img->matriz[i][j] = -1;
        else {
          fscanf(arq, "%d", &num_value);
          img->matriz[i][j] = num_value;
        }
      }
    }
  } else {
    // fread(&byte_value, sizeof(char), 1, arq);
    // printf("Okay");
    for (int i = 0; i < img->height +2; i++) {
      for (int j = 0; j < img->width + 2; j++) {
        if (i == 0 || i == img->height - 1)
          img->matriz[i][j] = -1;
        else if (j == 0 || j == img->width - 1)
          img->matriz[i][j] = -1;
        else {
          fread(&byte_value, sizeof(char), 1, arq);
          img->matriz[i][j] = byte_value;
          // fscanf(arq, "%d", &num_value);
          // arr[i][j] = num_value;
        }
      }
    }
  }
  printf("%s", img->P);
  printf("%d %d\n", img->width, img->height);
  printf("%d\n", img->max);
  int **arr2 = arrAlloc(img->width, img->height);
  initializeArr(arr2, img->width, img->height);

  int **arr3 = arrAlloc(3, 3);
  initializeArr(arr3, 3, 3);
  int soma = 0, n = 0;

  for (int i = 1; i < img->height + 1; i++) {

    for (int j = 1; j < img->width + 1; j++) {
      initializeArr(arr3, 3, 3);
      for (int c = -1; c < 2; c++) {
        for (int k = -1; k < 2; k++) {
          arr3[c + 1][k + 1] = img->matriz[i + c][j + k];
        }
      }
      soma = 0;
      n = 0;
      for (int c = 0; c < 3; c++) {
        for (int k = 0; k < 3; k++) {
          if (arr3[c][k] != -1) {
            soma = soma + arr3[c][k];
            n++;
          }
        }
      }
      arr2[i - 1][j - 1] = soma / n;
      // printf("%d ", n);
    }
  }
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }
  // for (int i = 0; i < img->height + 2; i++) {
  //   for (int j = 0; j < img->width + 2; j++) {
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  fclose(arq);
}

void extDadosMediana(char *arquivo, Imagem *img,int mediana) {
  FILE *arq;
  int i;
  char line[LINESIZE + 1];
  

  int offset = 2 * (mediana/2);

  printf("\n%d\n",offset);

  // abre o arquivo em leitura
  arq = fopen(arquivo, "r");
  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  // lê a primeira linha do arquivo para saber o tipo de imagem

  fgets(line, LINESIZE, arq);
  //img->P = line;
  strcpy(img->P, line);

  // le as linhas qcom as informa─oes de altura, largura e valor maximo
  // ignorando linhas de comentário
  printf("teste1");
  for (i = 0; i < 2; i++) {
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
  img->matriz = arrAlloc(img->width + offset, img->height + offset);
  initializeArr(img->matriz, img->width + offset, img->height + offset);
  // printf("teste");
  //  printf("testeokay");
  //  printf("\n%d\n", strncmp(img->P, "P2", 2));
  if (strncmp(img->P, "P2", 2) == 0) {
    for (int i = 0; i < img->height + offset; i++) {
      for (int j = 0; j < img->width + offset; j++) {
        if (i < offset/2 || i > img->height- offset/2+1)
          img->matriz[i][j] = -1;
        else if (j < offset/2 || j > img->width - offset/2+1)
          img->matriz[i][j] = -1;
        else {
          fscanf(arq, "%d", &num_value);
          img->matriz[i][j] = num_value;
        }
      }
    }
  } else {
    // fread(&byte_value, sizeof(char), 1, arq);
    // printf("Okay");
    for (int i = 0; i < img->height +2; i++) {
      for (int j = 0; j < img->width + 2; j++) {
        if (i == 0 || i == img->height - 1)
          img->matriz[i][j] = -1;
        else if (j == 0 || j == img->width - 1)
          img->matriz[i][j] = -1;
        else {
          fread(&byte_value, sizeof(char), 1, arq);
          img->matriz[i][j] = byte_value;
          // fscanf(arq, "%d", &num_value);
          // arr[i][j] = num_value;
        }
      }
    }
  }
  printf("%s", img->P);
  printf("%d %d\n", img->width, img->height);
  printf("%d\n", img->max);
  int **arr2 = arrAlloc(img->width, img->height);
  initializeArr(arr2, img->width, img->height);

  int **arrAux = arrAlloc(mediana, mediana);
  initializeArr(arrAux, mediana, mediana);
  int soma = 0, n = 0;

  for (int i = offset/2; i < img->height + offset/2; i++) {
    for (int j = offset/2; j < img->width + offset/2; j++) {
      initializeArr(arrAux, mediana, mediana);
      for (int c = 1-offset; c < offset; c++) {
        for (int k = 1-offset; k < offset; k++) {
          arrAux[c + 1][k + 1] = img->matriz[i + c][j + k];
        }
      }
      soma = 0;
      n = 0;
      for (int c = 0; c < mediana; c++) {
        for (int k = 0; k < mediana; k++) {
          if (arrAux[c][k] != -1) {
            soma = soma + arrAux[c][k];
            n++;
          }
        }
      }
      arr2[i - 1][j - 1] = soma / n;
      // printf("%d ", n);
    }
  }
  // for (int i = 0; i < img->height; i++) {
  //   for (int j = 0; j < img->width; j++) {
  //     printf("%d ", arr2[i][j]);
  //   }
  //   printf("\n");
  // }
  for (int i = 0; i < img->height + offset; i++) {
    for (int j = 0; j < img->width + offset; j++) {
      printf("%d ", img->matriz[i][j]);
    }
    printf("\n");
  }

  fclose(arq);
}

void extDadosLbp(char *arquivo, Imagem *img) {
  FILE *arq;
  int i;
  char line[LINESIZE + 1];
  

  // abre o arquivo em leitura
  arq = fopen(arquivo, "r");
  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  // lê a primeira linha do arquivo para saber o tipo de imagem

  fgets(line, LINESIZE, arq);
  //img->P = line;
  strcpy(img->P, line);

  // le as linhas qcom as informa─oes de altura, largura e valor maximo
  // ignorando linhas de comentário

  for (i = 0; i < 2; i++) {
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
  img->matriz = arrAlloc(img->width + 2, img->height + 2);
  initializeArr(img->matriz, img->width + 2, img->height + 2);
  // printf("teste");
  //  printf("testeokay");
  //  printf("\n%d\n", strncmp(img->P, "P2", 2));

  if (strncmp(img->P, "P2", 2) == 0) {
    for (int i = 1; i < img->height + 1; i++) {
      for (int j = 1; j < img->width + 1; j++) {
        fscanf(arq, "%d", &num_value);
        img->matriz[i][j] = num_value;
      }
    }
  } else {
    // fread(&byte_value, sizeof(char), 1, arq);
    // printf("Okay");
    for (int i = 1; i < img->height + 1; i++) {
      for (int j = 1; j < img->width + 1; j++) {
        fread(&byte_value, sizeof(char), 1, arq);
        img->matriz[i][j] = byte_value;
      }
    }
  }

  printf("%s", img->P);
  printf("%d %d\n", img->width, img->height);
  printf("%d\n", img->max);
  int **arr2 = arrAlloc(img->width, img->height);
  initializeArr(arr2, img->width, img->height);

  int **arr3 = arrAlloc(3, 3);
  initializeArr(arr3, 3, 3);
  int soma = 0, n = 0;

  for (int i = 1; i < img->height + 1; i++) {

    for (int j = 1; j < img->width + 1; j++) {
      initializeArr(arr3, 3, 3);
      for (int c = -1; c < 2; c++) {
        for (int k = -1; k < 2; k++) {
          if (img->matriz[i][j] <= img->matriz[i + c][j + k]) {
            arr3[c + 1][k + 1] = 1;
          }
        }
      }
      soma = 0;
      n = 0;
      for (int c = 0; c < 3; c++) {
        for (int k = 0; k < 3; k++) {
          if (c != 1 || k != 1) {
            soma = soma + arr3[c][k] * pow(2, n);
            n++;
          }
        }
      }
      arr2[i - 1][j - 1] = soma;
      // printf("%d ", n);
    }
  }
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }

  // for (int i = 0; i < img->height + 2; i++) {
  //   for (int j = 0; j < img->width + 2; j++) {
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  fclose(arq);
}

void extDadosRotacao(char *arquivo,Imagem *img,int angulo) {


  FILE *arq;
  // abre o arquivo em leitura
  arq = fopen(arquivo, "r");
  if (!arq) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  leImg(arq,img);

  printf("%s", img->P);
  printf("%d %d\n", img->height, img->width);
  printf("%d\n", img->max);

  int **arr2 = arrAlloc(img->height, img->width);
  initializeArr(arr2, img->height, img->width);

  for (int i = 0; i <= img->width - 1; i++) {
    for (int j = 0; j <= img->height - 1; j++) {

      arr2[i][j] = img->matriz[(img->height - 1) - j][i];
      // printf("%d ", n);
    }
  }
  

  for (int i = 0; i < img->width; i++) {
    for (int j = 0; j < img->height; j++) {
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }

  fclose(arq);
}
