/************************************************
 *
 ************************************************/

// Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Macro
#define LENGTH(array) ((int) sizeof(array) / sizeof(array[0]))

// External Variable(s)

// Prototype(s)
void make_empty(int *top);
bool is_empty(int *top);
bool is_full(int length, int *top);
void push(int arr[], int length, int *top, int num);
int pop(int arr[], int *top);


// Main
int main(void){
	bool loop = true;
	while (loop){
		// Create a stack
		int stack_size;
		int top = 0;
		printf("Insert a stack size: ");
		scanf("%d", &stack_size);
		while (getchar() != '\n');
		int stack_content[stack_size];

		// Process
		bool process = true;
		while (process){
			char move;
			printf("m: make_empty, e: is_empty, f: is_full, p: push, o: pop, q: quit\n");
			printf("Enter process which you want(m/e/f/p/o/q): ");
			move = toupper(getchar());
			while (getchar() != '\n');

			switch (move){
				case 'M': make_empty(&top); break;
				case 'E': is_empty(&top); break;
				case 'F': is_full(LENGTH(stack_content), &top); break;
				case 'P':
					int value;
					printf("What integer do you want to push in?: ");
					scanf("%d", &value);
					while(getchar() != '\n');
					push(stack_content,LENGTH(stack_content), &top, value);
					break;
				case 'O': pop(stack_content, &top); break;
				case 'Q':
					printf("Stack process terminated.\n");
					process = false;
					break;
				default : printf("Type legal characters on the first input.\n"); break;
			}
		}

		// Loop decision
		char reply;
		do {
			printf("Loop this program?(y/n): ");
			reply = toupper(getchar());
			while (getchar() != '\n');
			switch (reply){
				case 'Y': printf("\n===================================\n"); break;
				case 'N': printf("\n===================================\n");
						  printf("Program terminated.\n");
						  loop = false;
						  break;
				default : printf("Type y[Y] or n[N] on the first input.\n"); break;
			}
		} while (reply != 'Y' && reply != 'N');
	}
	system("pause");
	return 0;
}


// Function(s)
void make_empty(int *top){
	*top = 0;
}
bool is_empty(int *top){
	return *top == 0;
}
bool is_full(int length, int *top){
	return *top == length;
}
void push(int *arr, int length, int *top, int num){
	if (is_full(length, top)){
		printf("Since the stack is full, the push command was ignored.\n");
	}
	else
		arr[(*top)++] = num;
}
int pop(int *arr, int *top){
	if (is_empty(arr)){
		printf("Since the stack is empty, the pop command was ignored.\n");
		return -1;
	}
	int temp = arr[--(*top)];
	printf("You poped %d.\n", temp);
	return temp;
}
