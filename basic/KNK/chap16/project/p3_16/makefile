p3_16.exe: p3_16.o part.o readline.o
	gcc -o p3_16.exe p3_16.o part.o readline.o

p3_16.o: p3_16.c part.h
	gcc -c p3_16.c

readline.o: readline.h readline.c
	gcc -c readline.c

part.o: part.h readline.h part.c
	gcc -c part.c
