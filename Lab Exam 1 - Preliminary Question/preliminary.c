#include <stdio.h>

/*
    In this task, you should implement the `hello_ceng140()` function that reads (stdin) the inputs below and prints (stdout) the desired text.
*/

void hello_ceng140()
{
    /* WRITE YOUR CODE HERE */
    int programming_language_count;
    char favorite_programming_language;
    float cgpa = 0.00;
    scanf("%d %c %f",&programming_language_count, &favorite_programming_language, &cgpa);
    printf("I have learned %d programming languages. My favorite one is %c, and my CGPA is %.2f.\n",programming_language_count, favorite_programming_language,cgpa);
}

/*
    In this task, you should implement the model_complexity_calculator() function that calculates the estimated
    training time of a machine learning model considering its complexity level and dataset size.
*/

void model_complexity_calculator()
{
    /* WRITE YOUR CODE HERE */
    char complexity_level;
    int dataset_size;
    float skill = 0.00;
    scanf("%c %d",&complexity_level, &dataset_size);
    switch (complexity_level) {
        case 'B':
            skill = (0.5/1000)*dataset_size;
            break;
        case 'I':
            skill = (1.0/1000)*dataset_size;
            break;
        case 'A':
            skill = (2.5/1000)*dataset_size;
            break;
        case 'E':
            skill = (5.0/1000)*dataset_size;
            break;
        case 'S':
            skill = (10.0/1000)*dataset_size;
            break;
            
    }
    printf("%.2f",skill);
}

/*
    In this task, you should implement the alternating_sum_calculator() function that calculates the alternating sum of the digits of a given number.
*/

void alternating_sum_calculator()
{
    /* WRITE YOUR CODE HERE */
    int count = 1;
    long int number;
    int sum = 0, val = 0;
    scanf("%ld", &number);
    while(number > 0){
        val = number%10;
        if(count % 2 == 1){
            sum = sum + val;
            count++;
            number = number / 10;
        } else{
            sum = sum - val;
            count++;
            number = number / 10;
        }
    }
    if(sum > 0){
        printf("Positive alternating sum: %d\n",sum);
    }
    else if(sum < 0){
        printf("Negative alternating sum: %d\n",sum);
    } else{
        printf("The alternating sum is zero.\n");
    }
    
}

