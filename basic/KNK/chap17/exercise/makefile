17_17.exe: 17_17.o qsort.o
	gcc -o 17_17.exe 17_17.o qsort.o

17_17.o: 17_17.c ./qsort/qsort.h
	gcc -c 17_17.c

qsort.o: ./qsort/qsort.c ./qsort/qsort.h
	gcc -c ./qsort/qsort.c
