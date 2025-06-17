tpf: backend.o frontend.o main.o 
	gcc -Wall main.o frontend.o backend.o -o tpf

main.o: main.c backend.h frontend.h
	gcc -Wall main.c -c

backend.o: backend.h backend.c
	gcc -Wall backend.c -c

frontend.o: frontend.c frontend.o 
	gcc -Wall frontend.c -c

clean:
	rm *.o

# $ make -f makefileTPF.mak 

