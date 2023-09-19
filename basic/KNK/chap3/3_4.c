// What happens if we don't match the type format string with variable type?
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int i, j;
    float x;

    printf("Input 3 values for i, x and j: ");
    scanf("%d%f%d", &i, &x, &j);

    printf("call: %d %f %d\n", i, x, j);
    system("pause");
    return 0;

    /* if you input 10.3 5 6, the first %d cannot take the part .3, hence .3 go to %f,
    finally 5 enter last %d */
}
