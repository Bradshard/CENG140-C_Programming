#include "pointerUpdate.h"
#include <stdio.h>

void update(int * arr[], int length){
    
    /*Do your work here */
    int val, index, i;
    int *first = arr[0];
    /* to initialize */
    for(i = 0; i < length; i++){
        val = *arr[i];                 /* assign value via dereferencing. */
        index = val % length;      /* new address based on length */
        arr[i] = first + index;             /* switch addresses */
    }

}
