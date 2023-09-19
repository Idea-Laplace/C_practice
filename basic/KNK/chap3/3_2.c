//Displaying a float variable in various formats.
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    float x;
    printf("Enter a number of type float: ");
    scanf("%f", &x);

    //Exponential notation, left-justified in a field of size 8, one digit after the decimal point
    printf("\nformat %%-8.1e: %-8.1e\n", x);

    //Exponential notation, right-justified in a field of size 10, six digit after the decimal point
    printf("format %%10.6e: %10.6e\n", x);

    //Fixed-decimal notation, left-justified in a field of size 8, three digit after the decimal point
    printf("format %%-8.3f: %-8.3f\n", x);
    
    //Fixed-decimal notation, right-justified in a field of size 6, no digit after the decimal point
    printf("format %%6.f: %6.f\n", x);

    system("pause");
    return 0;
}
