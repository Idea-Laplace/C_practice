#include <stdio.h>
#include <stdlib.h>
#define INCHES_PER_POUND 166
// Computes the dimensional weight of a box from input provided by the user

int main(void)
{
    int volume, weight;

    printf("Input volume: ");
    scanf("%d", &volume);

    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("Demensional weight(pounds): %4d\n", weight);
    
    system("pause");
    return 0;
}
