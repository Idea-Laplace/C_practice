p4_16.exe: p4_16.o part.o readline.o
	gcc -o p4_16.exe p4_16.o part.o readline.o

p4_16.o: p4_16.c part.h
	gcc -c p4_16.c

readline.o: readline.h readline.c
	gcc -c readline.c

part.o: part.h readline.h part.c
	gcc -c part.c
