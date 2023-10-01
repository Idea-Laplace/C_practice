#include <stdio.h>
#include <stdlib.h>

/* Count digits, white space(blank, newline, tab), others */

int main(){
    int c, i, nwhite, nother;
    int ndigit[10];
    
    nwhite = nother = 0;
    for(i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while((c=getchar()) != EOF){
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];    /* This trick is possible since the numeric values of '0'~'9' is consecutive. */
        else if (c == ' '||c == '\n'||c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits:\n");
    for(i = 0; i < 10; ++i)
        printf("%d: %d\n", i, ndigit[i]);
    printf("white space: %3d\t other: %3d\n", nwhite, nother);
    
    system("pause");
    return 0;
}
