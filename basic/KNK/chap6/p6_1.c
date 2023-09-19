#include <stdio.h>
#include <stdlib.h>


int main (void){
	float fnum, max = 0.0f;
	int count = 0;
	printf("If you want to stop, enter a non-positive number.\n");
	do {
		printf("Enter a number: ");
		scanf("%f", &fnum);
		// When the input is non positive in the first place.
		if (count == 0 && fnum <= 0);
			max = fnum;
			break;

		// Normal case.
		if (fnum > max)
			max = fnum;

		++count;
	} while (fnum > 0);
	

	printf("The largest number entered was %g.\n", max);
	system("pause");
	return 0;
}
