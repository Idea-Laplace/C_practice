#include <stdio.h>
#include <stdlib.h>     /* To use system("pause")*/
#define IN 1    /* state of in-word */
#define OUT 0   /* state of out-word */

int main()
{
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;

    while((c=getchar()) != EOF){
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' '||c == '\n'||c == '\t')
            state = OUT;
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }

    printf("lines: %3d\tcharacters: %4d\twords: %3d\n\n", nl, nc, nw);
    system("pause");
    return 0;
}
