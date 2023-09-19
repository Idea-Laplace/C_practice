#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int bill;

    printf("Enter a dollar amount: ");
    scanf("%d", &bill);

    printf("$20 bills: %2d\n", bill/20);
    bill = bill - 20*(bill/20);

    printf("$10 bills: %2d\n", bill/10);
    bill = bill - 10*(bill/10);

    printf("$ 5 bills: %2d\n", bill/5);
    bill = bill - 5*(bill/5);

    printf("$ 1 bills: %2d\n", bill);

    system("pause");
    return 0;
}
