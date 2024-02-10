/*
	(a) Assetions can be used to test for two kinds of problems:
		(1) problems that should never occur if the program is correct.
		(2) problems that are beyond the control of the program.
		Explain why assert is best suited for problems  int the first category.

		They provide a means to express the programmer's understanding of the program's behavior
		at specific points in the code.

		They help detect and diagnose programming errors early in the development process,
		enabling faster debugging and resolution of issues.

		They allow developers to document and enforce preconditions,
		postconditions, and invariants in the code, thereby improving code quality and maintainability.
	
	(b) Give three examples of problems that are beyond the control of the program.

		Hardware failures: Malfunctions or defects in hardware components such as CPU, memory modules,
		or storage devices can cause unexpected behavior or system crashes that are beyond the control of the software.

		Operating system limitations: The behavior of a program may be affected by limitations or constraints 
		imposed by the underlying operating system, such as file system restrictions, resource limits, or security policies.

		Network issues: Connectivity problems, network congestion, or server outages can disrupt communication 
		between software components or services, leading to failures or degraded performance that are outside the program's control.
*/


// #define NDEBUG
#include <assert.h>
#include <stdio.h>

int main(void) {
	int arr[10];
	int i;
	printf("Enter an index for an integer array of length 10: ");
	scanf("%d", &i);
	assert(0 <= i && i < 10);
	printf("Selected index: %d\n", i);
	return 0;
}
/*
Enter an index for an integer array of length 10: 10
1_24: 1_24.c:20: main: Assertion `0 <= i && i < 10' failed.
Aborted
*/
