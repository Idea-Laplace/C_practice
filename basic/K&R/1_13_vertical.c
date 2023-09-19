#include <stdio.h>
#include <stdlib.h>
#define IN 1    /* state information when the cursor is IN a word */
#define OUT 0   /* state information when the cursor is not in a word */

/* This program is a solution for exercise 1-13 in K&R as a vertical version */

int main(void){
    int word_length[20];
    int i, j, c, state, max, temp;

    state = OUT;
    max = temp = 0;

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
   
    /* ============= Drawing histogram part ============== */
    for (i = 0; i < 20; ++i)
        if (max < word_length[i])
            max = word_length[i];

    while(max > 0){
        for (i = 0; i < 20; ++i)
            if (word_length[i] < max)
                printf("   ");
            else
                printf(" o ");
        printf("\n");
        --max;
    }
    for (i = 0; i < 20; ++i)
        printf("%2d ", i);

    system("pause");
    return 0;
}
