//This program is for notifying you of the pitfalls in scanf
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int x;

    // ====================================================
    //" %d" and "%d" are equivalent in scanf
    printf("test \"%%d\": ");
    scanf("%d", &x);
        
    printf("test \" %%d\": ");
    scanf("%d", &x);
    
    // ===================================================
    //"%d-%d-%d" and "%d -%d -%d" are different in scanf
    printf("test \"%%d-%%d-%%d\": ");
    scanf("%d-%d-%d", &x, &x, &x);
        
    printf("test \"%%d -%%d -%%d\": ");
    scanf("%d -%d -%d", &x, &x, &x);
    
    // ===================================================
    //"%f" and "%f " are different in scanf
    printf("test \"%%f\": ");
    scanf("%f", &x);
        
    printf("test \"%%f \": ");
    scanf("%f ", &x);
    
    // ===================================================
    //"%f,%f" and "%f, %f" are different in scanf
    printf("test \"%%f,%%f\": ");
    scanf("%f", &x, &x);
        
    printf("test \"%%f, %%f\": \n");
    scanf("%f ", &x, &x);

    system("pause");
    return 0;
}
