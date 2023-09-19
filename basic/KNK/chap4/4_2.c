#include <stdio.h>
#include <Stdlib.h>


// In C89, (-9)/7 could be either -1 or -2, depending on the implementation.
// On the other hand, the value of -(i/j) is always -1, regardless of the implementation.
// In C99, the value of (-i)/j must be equal to the value of -(i/j)
int main(void)
{
    int mode, loop = 1, i, j;
    while(loop == 1)
    {
        mode = 0;
        printf("Enter 2 positive integers: ");
        scanf("%d%d", &i, &j);

        printf("\nValue comparison\n");
        printf("(-i) / j : %d\n", (-i)/j);
        printf("-(i / j) : %d\n\n", -(i/j));

        while (mode != 'y' && mode != 'n')
        {
            printf("Do you want to check another case?(y/n): ");
            getchar();
            mode = getchar();
            if (mode == 'y')
                printf("\n==========================\n");
            else if(mode == 'n')
            {
                printf("Program terminated.\n");
                loop = 0;
            }
            else
                printf("Enter y or n.\n");

        }
    }
    system("pause");
    return 0;
}

