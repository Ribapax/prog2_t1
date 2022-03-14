CFLAGS = -Wall

CC = gcc

LIBS = -lm

all: pgmnega pgmrotacao pgmlimiar pgmmedia pgmlbp pgmmediana

clean:
	-rm -f *.o

purge: clean
	-rm -f pgmnega pgmrotacao pgmlimiar pgmmedia pgmlbp pgmrotacao pgmmediana

pgmnega: pgmnega.o  tratlcmd.o acessopgm.o acessoEstruturas.o $(LIBS)

pgmrotacao: pgmrotacao.o  tratlcmd.o acessopgm.o acessoEstruturas.o $(LIBS)

pgmmediana: pgmmediana.o  tratlcmd.o acessopgm.o acessoEstruturas.o $(LIBS)

pgmlbp: pgmlbp.o  tratlcmd.o acessopgm.o acessoEstruturas.o $(LIBS)

pgmlimiar: pgmlimiar.o  tratlcmd.o acessopgm.o acessoEstruturas.o $(LIBS)

pgmmedia: pgmmedia.o  tratlcmd.o acessopgm.o acessoEstruturas.o $(LIBS)


# regras de compilação
pgmnega.o: pgmnega.c acessoEstruturas.o

pgmrotacao.o: pgmrotacao.c acessoEstruturas.o

pgmlbp.o: pgmlbp.c acessoEstruturas.o

pgmlimiar.o: pgmlimiar.c acessoEstruturas.o

pgmmedia.o: pgmmedia.c acessoEstruturas.o

pgmmediana.o: pgmmediana.c acessoEstruturas.o

tratlcmd.o: tratlcmd.c tratlcmd.h acessoEstruturas.o

acessopgm.o: acessopgm.c acessopgm.h acessoEstruturas.o

acessoEstruturas.o: acessoEstruturas.c acessoEstruturas.h



