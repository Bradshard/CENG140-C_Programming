#include <stdio.h>

int main() {
    /* implement here */
    int weekdays = 5;
    float days[5];
    float avg = 0.0;
    char name[5][4] = {"Mon", "Tue", "Wed", "Thu", "Fri"};
    int i;
    
    for(i = 0; i < weekdays; i++){
      scanf("%f", &days[i]);
      days[i] = (days[i] - 32)/1.8;
      avg += days[i];
      printf("Celsius on %s: %.2f\n", name[i] ,days[i]);
    }
    avg /= weekdays;
    printf("Average: %.2f\n",avg);
    return 0;
}
