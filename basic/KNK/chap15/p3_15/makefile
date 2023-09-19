qsort_print: qsort_print.o quicksort.o
	gcc -o qsort_print qsort_print.o quicksort.o

quicksort.o: quicksort.c quicksort.h
	gcc -c quicksort.c

qsort_print.o: qsort_print.c quicksort.h
	gcc -c qsort_print.c
