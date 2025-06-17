# Compilador y flags
cc = gcc -Wall
# Librerías de Allegro necesarias (pueden variar según el programa)
LIBS = $(shell pkg-config allegro-5 allegro_font-5 allegro_primitives-5 --libs --cflags)
# Nombre del ejecutable
TARGET = ap2
#ARCHIVO FUENTE
SRC = ap2.c

$(TARGET): $(SRC)
	$(cc) -o$(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)