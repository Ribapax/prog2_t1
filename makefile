CFLAGS = -Wall

CC = gcc


#pgmnega: pgmnega.c teste.c teste.h
#	gcc -Wall pgmnega.c teste.c -o pgmnega

all: pgmnega pgmrotacao pgmlimiar pgmmedia pgmlbp pgmrotacao pgmmediana

clean:
	-rm -f *.o

purge: clean
	-rm -f pgmnega pgmrotacao

pgmnega: pgmnega.o teste.o tratlcmd.o acessopgm.o -lm

pgmrotacao: pgmrotacao.o teste.o tratlcmd.o acessopgm.o -lm

pgmmediana: pgmmediana.o teste.o tratlcmd.o acessopgm.o -lm

pgmlbp: pgmlbp.o teste.o tratlcmd.o acessopgm.o -lm

pgmlimiar: pgmlimiar.o teste.o tratlcmd.o acessopgm.o -lm

pgmmedia: pgmmedia.o teste.o tratlcmd.o acessopgm.o -lm





# regras de compilação
pgmnega.o: pgmnega.c teste.h

pgmrotacao.o: pgmrotacao.c teste.h

pgmlbp.o: pgmlbp.c teste.h

pgmlimiar.o: pgmlimiar.c teste.h

pgmmedia.o: pgmmedia.c teste.h

pgmmediana.o: pgmmediana.c teste.h


teste.o: teste.c teste.h

tratlcmd.o: tratlcmd.c tratlcmd.h

acessopgm.o: acessopgm.c acessopgm.h


