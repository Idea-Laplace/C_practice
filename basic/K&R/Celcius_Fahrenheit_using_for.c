#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fahr;
    int celcius;

    for (fahr = 0; fahr <= 300; fahr += 20){
        celcius = 5*(fahr-32)/9;
        printf("fahr: %6d\tcelcius: %6d\n", fahr, celcius);
        }

    system("pause");
    return 0;
}
