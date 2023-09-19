#include <stdio.h>
#include <stdlib.h>

//Without using %o format, get the given goal.

int main(void)
{
    int i, decimal_num, octal_num[5];
    for (i = 0; i < 5; ++i)
        octal_num[i] = 0;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &decimal_num);
    for (i = 0; i < 5; ++i)
    {
        octal_num[i] = decimal_num % 8;
        decimal_num /= 8;
    }

    printf("In octal, your number is: ");
    for (i = 0; i < 5; ++i)
        printf("%d", octal_num[4 - i]);
    printf("\n");

    system("pause");
    return 0;
}
