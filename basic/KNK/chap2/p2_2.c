#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592f
#define VOLUME_CONSTANT 4.0f/3.0f

// This program is for calculating volume of a sphere according to the input radius

int main(void)
{
    int radius;

    printf("Input radius: ");
    scanf("%d", &radius);

    printf("Volume of the sphere of radius %d:\t%6.2f\n", radius, VOLUME_CONSTANT * PI * radius * radius * radius);

    system("pause");
    return 0;
}
