#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while(fahr <= upper)
        {
            celcius = 5*(fahr-32)/9;
            printf("fahr: %6dF\tcelcius: %6dC\n", fahr, celcius);
            fahr += step;
        }

    printf("\n");
    
    float fahr_f, celcius_f;

    for (fahr_f = 0; fahr_f<=300; fahr_f+=20){
        celcius_f = (5.0/9.0)*(fahr_f - 32);
        printf("fahr: %6.2fF\tcelcius: %6.2fC\n", fahr_f, celcius_f);
        }

    system("pause");
    return 0;
}
