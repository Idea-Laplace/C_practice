#include <stdio.h>
#include <stdlib.h>

int main(){
    float c, nc, nl, nb, nt;
    nc = nl = nb = nt = 0;
    while((c = getchar()) != EOF){
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else
            ++nc;
    }

    printf("net char: %4.0f\tblanks: %3.0f\ttabs: %3.0f\tlines: %3.0f\n", nc, nb, nt, nl);
    system("pause");
    return 0;
}
