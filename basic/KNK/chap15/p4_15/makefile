remind: remind.o template.o readline.o
	gcc -o remind remind.o template.o readline.o

remind.o: remind.c template.h readline.h
	gcc -c remind.c

template.o: template.c template.h
	gcc -c template.c

readline.o: readline.c readline.h
	gcc -c readline.c
