#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int num1, num2, num3;

    printf("Enter phone number[(xxx) xxx-xxxx] : ");
    scanf("(%d)%d-%d", &num1, &num2, &num3);
    printf("You entered %.3d.%.3d.%.4d\n\n", num1, num2, num3);

    system("pause");
    return 0;
}
