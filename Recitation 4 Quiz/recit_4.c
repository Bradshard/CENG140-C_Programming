#include <stdio.h>
#include "recit_4.h"


int combinations(int n, int k){
    float f;
    if(k == 0){
        printf("(%d %d)\n",n,k);
        return 1;
    }
    else if(k > 0){
        if(n-k < k){
            f = (float) n/(n-k);
            printf("(%d %d)\n",n,k);
            printf("(%d %d)\n",n,n-k);
            return f*combinations(n-1, n-k-1);
        } else if(n-k >= k){
            f = (float) n/k;
            printf("(%d %d)\n",n,k);
            return f*combinations(n-1,k-1);
            
        }
    }
    return 0;
}

double sine_rec(double x, int count, int iter, double y) {
    if (count > iter){
        return x;
        /* if count started from 0 then count == iter, but it didn't.*/
        
    }
    if(count % 2 == 1 && count > 1){
        if(absolute((double) (power(y, 2*count-1) / factorial(2*count-1))) >= ERROR){
            x = x  + (double) (power(y, 2*count-1) / factorial(2*count-1));
            printf("sin(%.6f) = %.6f at recursive call %d\n",y, x, count);

            count++;
            return sine_rec(x, count, iter, y);
        } else{
            return x;
        }

    }
    else if(count % 2 == 0 && count > 1){
        if( absolute((double) (power(y, 2*count-1) / factorial(2*count-1))) >= ERROR ){
            x = x  - (double) (power(y, 2*count-1) / factorial(2*count-1));
            printf("sin(%.6f) = %.6f at recursive call %d\n",y, x, count);

            count++;
            return sine_rec(x, count, iter, y);
        } else{
            return x;
        }

    } else{
        printf("sin(%.6f) = %.6f at recursive call %d\n",y, x, count);
        count++;
        return sine_rec(x, count, iter, y);
    }

}

double sine(double x, int iter) {
    double y = x;
    return sine_rec(x, 1, iter, y);
}
