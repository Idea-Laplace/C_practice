p1_17.exe: p1_17.o readline.o inventory_array_ver.o
	gcc -o p1_17.exe p1_17.o inventory_array_ver.o readline.o

p1_17.o: readline.h inventory_array_ver.h p1_17.c
	gcc -c p1_17.c

readline.o: readline.c readline.h
	gcc -c readline.c

inventory_array_ver.o: inventory_array_ver.c inventory_array_ver.h
	gcc -c inventory_array_ver.c
