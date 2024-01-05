justify: justify.o word.o line.o
	gcc -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	gcc -c justify.c

word.o: word.h word.c
	gcc -c word.c

line.o: line.h line.c
	gcc -c line.c
