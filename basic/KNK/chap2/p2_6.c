#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//This program displays the value of the following polynomial 3x^5+2x^4-5x^3-x^2+7x-6
int main(void)
{
    int x, loop = 1;
    clock_t start;
    
    printf("Input a value of x: ");
    scanf("%d", &x);
    start = clock();

    // Normal calculation p2_5
    printf("Calculated value: %5ld\n", 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6);
    printf("Time consumed: %.9esec\n", clock() - start);

    // Honer's Rule calculation p2_6
    start = clock();
    printf("Calculated value by Honer's Rule: %5d\n", ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6);
    printf("Time consumed: %.9esec\n", clock() - start);

    system("pause");
    return 0;
}
