8_17.exe: 8_17.o stack.o
	gcc -o 8_17.exe 8_17.o stack.o

8_17.o: 8_17.c ./stack/stack.h
	gcc -c 8_17.c

stack.o: ./stack/stack.c ./stack/stack.h
	gcc -c ./stack/stack.c
