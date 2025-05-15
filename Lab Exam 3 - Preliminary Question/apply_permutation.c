#include "questions.h"

int* apply_permutation(int n, const int data[], const int perm[])
{
    /* YOUR CODE GOES HERE  */
    int i;
    int* result = (int*) malloc(n * sizeof(int));
    if (result == NULL){
        return NULL;
    }

    
    for (i = 0; i < n; ++i)
    {
        result[i] = data[perm[i]]; /* apply permutation*/
    }
    return result;
}