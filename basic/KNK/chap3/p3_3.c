#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int gsl_prefix, group_identifier, publisher_code,\
        item_number, check_digit;

    printf("Enter ISBN(No white-space character is allowed) : ");
    scanf("%d-%d-%d-%d-%d", &gsl_prefix, &group_identifier, \
            &publisher_code, &item_number, &check_digit);

    printf("GSl prefix: %d\n", gsl_prefix);
    printf("Group Identifier : %d\n", group_identifier);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item number: %d\n", item_number);
    printf("Check digit: %d\n\n", check_digit);

    system("pause");
    return 0;
}
