#include <stdio.h>
#include <stdlib.h>


int main(void){
	int i, j, k;
	
	printf("Enter integer values for i, j and k.(Try first 3 4 5): ");
	scanf("%d%d%d", &i, &j, &k);
	
	printf("Checking the process of \'i < j || ++j < k\'...\n");
	printf("%d\n", i<j || ++j<k);
	printf("i: %d\tj: %d\tk: %d\n", i, j, k);
	printf("You can see the effect of short-circuit of binary logical operators.\n\n");
	
	//====================================================================================
	printf("Enter integer values for i, j and k.(Try first 7 8 9: ");
	scanf("%d%d%d", &i, &j, &k);
	
	printf("Checking the process of \'i - 7 && j++ < k\'...\n");
	printf("%d\n", i - 7 && j++ < k);
	printf("i: %d\tj: %d\tk: %d\n", i, j, k);
	printf("You can see the effect of short-circuit of binary logical operators.\n\n");
	
	//===================================================================================
	printf("Enter integer values for i, j and k.(Try first 7 8 9: ");
	scanf("%d%d%d", &i, &j, &k);
	
	printf("Checking the process of \'(i = j) && (j = k)\'...\n");
	printf("%d\n", (i = j) && (j = k));
	printf("i: %d\tj: %d\tk: %d\n", i, j, k);
	printf("You can see the effect of short-circuit of binary logical operators.\n");
	printf("Keep in mind that the order of assignment operators are preceded by most operators in C.\n\n");
	
	//===================================================================================
	printf("Enter integer values for i, j and k.(Try first 1 1 1: ");
	scanf("%d%d%d", &i, &j, &k);
	
	printf("Checking the process of \' ++i || ++j && ++k\'...\n");
	printf("%d\n", ++i || ++j && ++k);
	printf("i: %d\tj: %d\tk: %d\n", i, j, k);
	printf("You can see the effect of short-circuit of binary logical operators.\n");
	printf("Note that && precedes || and in left associative.\n\n");
	
	system("pause");
	return 0;
}
