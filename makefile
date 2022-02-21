CFLAGS = -Wall

CC = gcc


#pgmnega: pgmnega.c teste.c teste.h
#	gcc -Wall pgmnega.c teste.c -o pgmnega

all: pgmnega pgmrotacao

clean:
	-rm -f *.o

purge: clean
	-rm -f pgmnega pgmrotacao



pgmnega: pgmnega.o teste.o

pgmrotacao: pgmrotacao.o teste.o


# regras de compilação
pgmnega.o: pgmnega.c teste.h

pgmrotacao.o: pgmrotacao.c teste.h


teste.o: teste.c teste.h


# regras de compilação


