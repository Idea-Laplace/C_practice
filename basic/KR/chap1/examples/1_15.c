#include <stdio.h>
#include <stdlib.h>

/* This program configure a function that convert Fahrenheit to Celcius */

int F_to_C(int f);
int C_to_F(int c);

int main(){
    int fahr, celc;

    for (fahr = 0; fahr < 300; fahr = fahr + 20)
        printf("Fahrenheit: %3d     Celcius: %3d\n", fahr, F_to_C(fahr));

    printf("\n");

    for (celc = 0; celc < 300; celc = celc + 20)
        printf("Celcius: %3d     Fahrenheit: %3d\n", celc, C_to_F(celc));

    system("pause");
    return 0;
}


int F_to_C(int f){
    int c;

    c = 5 * (f - 32) / 9;
    return c;
}

int C_to_F(int c){
    int f;

    f = 9 * c / 5 + 32;
    return f;
}
