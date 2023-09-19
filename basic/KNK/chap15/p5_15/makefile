p5_15: p5_15.o stack.o rpn.o template.o
	gcc -o p5_15 p5_15.o stack.o rpn.o template.o

p5_15.o: p5_15.c stack.h rpn.h template.h
	gcc -c p5_15.c

stack.o: stack.c stack.h
	gcc -c stack.c

rpn.o: rpn.c rpn.h
	gcc -c rpn.c

template.o: template.c template.h
	gcc -c template.c
