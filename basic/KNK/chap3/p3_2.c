#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int item_number, month, date, year;
    float price;

    // Input
    printf("Enter item number: ");
    scanf("%d", &item_number);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy) : ");
    scanf("%d /%d /%d", &month, &date, &year);

    // Output
    printf("\n===========================================\n");
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%-4d\t\t$%7.2f\t%2.2d/%2.2d/%4.4d\n", item_number, price, month, date, year);
    printf("===========================================\n\n");

    system("pause");
    return 0;
}
