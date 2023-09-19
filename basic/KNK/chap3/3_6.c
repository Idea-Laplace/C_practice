//Adds 2 Fractions
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int num1, denum1, num2, denum2, result_num, result_denum, loop = 1 ;
    int c, dummy;

    while (loop == 1)
    {
        c = 0;
        printf("Do not type nondigits, if you do, please terminate this program.\n");
        printf("Enter first fraction: ");
        scanf("%d /%d", &num1, &denum1);    // A space in "%d /%d" is important for users to type white space

        printf("Enter second fraction: ");
        scanf("%d /%d", &num2, &denum2);    // A space in "%d /%d" is important for users to type white space

        result_num = num1 * denum2 + num2 * denum1;
        result_denum = denum1 * denum2;

        printf("The sum is %d/%d, not reduced to lowest form.\n\n", result_num, result_denum);

        while(c != 'y' && c != 'n'){
            printf("Do you want to try another addtion?(y/n) ");
            dummy = getchar();
            c = getchar();
            if (c == 'y') 
                printf("\n=========================================================\n");
            else if (c == 'n')
                loop = 0;
            else
                printf("Type y or n.\n");
        }
    }
        printf("Program terminated.\n");
        system("pause");
        return 0;
}
