CC := gdb
cajero: main.o display.o
	${CC} -Wall main.o display.o -o cajero

main.o: main.c mensajes.h display.h
	${CC} -Wall main.c -c

display.o: display.c display.h
	${CC} -Wall display.c -c

clean:
	rm *.o

