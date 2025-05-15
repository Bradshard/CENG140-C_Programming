/* THIS FILE IS NOT GRADED */
/* THIS FILE IS FOR STUDENTS TO TEST THEIR CODES */

#include "questions.h"

int main()
{
    int data[5] = {4,8,2,1,6};
    int perm[5] = {2,3,1,4,0};
    int *output = apply_permutation(5, data, perm);
    for(i = 0; i < 5; i++)
    {
        printf("output[%d]: %d\n", i, output[i]);
    }
    free(output);
    return 0;
}