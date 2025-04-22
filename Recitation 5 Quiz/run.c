#include <stdio.h>
#include "pointerUpdate.h"

int main(){

int array[5] = {14,8,6,5,12}; /* you can try different arrays */
int *ptrs[5], i;

for(i=0; i < 5; i++) /* DO NOT REMOVE */
    ptrs[i] = array+i;

update(ptrs, 5); /* call your function here */

for(i=0; i < 5; i++) /* DO NOT REMOVE */
    printf("%d ", *ptrs[i]); 

printf("\n");
return 0;
}
