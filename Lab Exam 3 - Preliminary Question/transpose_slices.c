#include "questions.h"

int*** transpose_slices(int B, int R, int C, int ***input)
{
    /* YOUR CODE GOES HERE  */
    int b, i, j;
    int*** output = (int***) malloc(B * sizeof(int**));
    if (output == NULL) return NULL;

    for (b = 0; b < B; ++b)
    {
        output[b] = (int**) malloc(C * sizeof(int*)); /* Transposed: C rows */
        if (output[b] == NULL){ return NULL;}

        for (i = 0; i < C; ++i)
        {
            output[b][i] = (int*) malloc(R * sizeof(int)); /* Transposed: R cols */
            if (output[b][i] == NULL){return NULL;}

            for (j = 0; j < R; ++j)
            {
                output[b][i][j] = input[b][j][i]; /* Transpose: swap indices */
            }
        }
    }
    return output;
}