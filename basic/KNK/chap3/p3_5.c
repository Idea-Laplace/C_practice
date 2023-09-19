#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    // Input
    int i, j, magic_square[16], row_sum[4], column_sum[4], diagonal1, diagonal2;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    for (i = 0; i < 16; ++i)
        scanf("%d", &magic_square[i]);


    // Calculation ========================================================================
    for (j = 0; j < 4; ++j)
    {
        row_sum[j] = magic_square[4*j] + magic_square[4*j+1] + magic_square[4*j+2] + magic_square[4*j+3];
        column_sum[j] = magic_square[j] + magic_square[j+4] + magic_square[j+8] + magic_square[j+12];
    }

    diagonal1 = magic_square[0] + magic_square[5] + magic_square[10] + magic_square[15];
    diagonal2 = magic_square[3] + magic_square[6] + magic_square[9] + magic_square[12];


    // Output =============================================================================
    printf("\n");
    for (i = 0; i < 16; i += 4)
        printf("%2d %2d %2d %2d\n", magic_square[i], magic_square[i+1], magic_square[i+2], magic_square[i+3]);  
        
    printf("\nRow sums: %d %d %d %d\n", row_sum[0], row_sum[1], row_sum[2], row_sum[3]); 
    printf("Column sums: %d %d %d %d\n", column_sum[0], column_sum[1], column_sum[2], column_sum[3]); 
    printf("Diagonal sums: %d %d\n", diagonal1, diagonal2);
    system("pause");
    return 0;
}
