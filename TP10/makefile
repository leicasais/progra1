CC := gcc -Wall
arch := ej
# Librerías de Allegro necesarias (pueden variar según el programa)
LIBS = $(shell pkg-config allegro-5 allegro_font-5 allegro_primitives-5 --libs --cflags)

$(arch): ej3.o 
	${CC} ej3.o -o ${arch} ${LIBS}

ej3.o: ej3.c portlib.h
	${CC} ej3.c -c
clean:
	rm * .o
