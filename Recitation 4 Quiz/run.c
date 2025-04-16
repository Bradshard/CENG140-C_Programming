#include <stdio.h>
#include "recit_4.h"

double power(double base, int exp){
    double result = 1;
    while(exp--){
        result *= base;
    }
    return result;
}

double factorial(int n){
    double result = n;
    while(--n > 0){
        result *= n;
    }
    return result;
}

double absolute(double d){
    return d<0 ? -1*d : d;
}


int main(){

    printf("You can modify this file for your own test cases\n");
    printf("This file is not used in evaluation\n");
    

    return 0;
}
