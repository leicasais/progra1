prog: main.o display.o 
	gcc main.o display.o -o prog -Wall
main.o: main.c mensajes.h display.h
	gcc main.c -c -Wall
display.o: display.c display.h
	gcc display.c -c -Wall

clean:
	rm -f *.o prog
# $ make -f makefile 
#Reglas q se ejecutan en consola si se modifica mensajes.h:
# $ gcc main.c -c -Wall
# $ gcc main.o display.o -o prog -Wall

