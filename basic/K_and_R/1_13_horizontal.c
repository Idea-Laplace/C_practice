#include <stdio.h>
#include <stdlib.h>
#define IN 1    /* state information when the cursor is IN a word */
#define OUT 0   /* state information when the cursor is not in a word */

/* This program is a solution for exercise 1-13 in K&R as a horizontal version */

int main(void){
    int word_length[20];
    int i, j, c, state, temp;

    state = OUT;
    temp = 0;

    for (i = 0; i < 20; ++i)
        word_length[i] = 0;

    while((c = getchar()) != EOF){
        if (c == ' '||c == '\t'||c == '\n'){
            if (state == IN){
                state = OUT;
                if (temp >= 20)
                    ++word_length[0];
                else
                    ++word_length[temp];
                temp = 0;
            }
        }
        else {
            if (state == OUT)
                state = IN;
            ++temp;
        }
    }
   
    for (i = 1; i < 20; ++i){
        printf("number of the word of length %2d: ", i);
        for (j = 0; j < word_length[i]; ++j)
            printf("o");
        printf("\n");
    }


    for (j = 0; j < word_length[0]; ++j)
        printf("o");
    printf("\n");
    system("pause");
    return 0;
}
