addition: addition.o read.o template.o
	gcc -o addition addition.o read.o template.o

addition.o: template.h addition.c
	gcc -c addition.c

read.o: read.c read.h
	gcc -c read.c

template.o: template.h read.h template.c
	gcc -c template.c
