#include <stdio.h>
/* you can add math library */
#include <math.h>
#define DISTANCE 1000000.0

int main()
{
    int i;
    int xcoors[10];
    int ycoors[10];
    /* declare your variables */
    int px, py;
    double distance = DISTANCE;
    double dist;
    int special_i;
    
    for (i=0; i<10; i++){
        scanf("%d ", &xcoors[i]);
    }
    
    for (i=0; i<10; i++){
        scanf("%d ", &ycoors[i]);
    }
    scanf("%d ", &px);
    scanf("%d ", &py);
    
     
    /* implement your loop then */
    for (i=0; i<10; i++){
        dist = sqrt(pow(px - xcoors[i],2)+pow(py - ycoors[i],2));
        if(dist < distance){
            distance = dist;
            special_i = i;
        }
    }
    
    printf("P = (%d,%d), nearest point index = %d, distance = %.1f\n",px,py,special_i,distance);
    /* print the result */

    return 0;
}
