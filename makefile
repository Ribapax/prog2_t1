CFLAGS = -Wall

CC = gcc


#pgmnega: pgmnega.c teste.c teste.h
#	gcc -Wall pgmnega.c teste.c -o pgmnega

all: pgmnega pgmrotacao

clean:
	-rm -f *.o

purge: clean
	-rm -f pgmnega pgmrotacao

pgmnega: pgmnega.o teste.o tratlcmd.o acessopgm.o

pgmrotacao: pgmrotacao.o teste.o


# regras de compilação
pgmnega.o: pgmnega.c teste.h

pgmrotacao.o: pgmrotacao.c teste.h

teste.o: teste.c teste.h

tratlcmd.o: tratlcmd.c tratlcmd.h

acessopgm.o: acessopgm.c acessopgm.h


