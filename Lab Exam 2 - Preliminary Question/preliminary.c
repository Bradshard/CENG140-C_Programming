#include <stdio.h>


void to_upper(char sentence[])
{
    /* WRITE YOUR CODE HERE */
    int length = 0;
    const char OFFSET = 'a' - 'A'; /* small letters are bigger in int.*/
    int i;
    while (sentence[length] != '\0') {
        length++;
    }

    for(i = 0; i<length; i++){
        if(sentence[i] > 'Z' && sentence[i] != ' '){
            sentence[i] = sentence[i] - OFFSET;
            printf("%c",sentence[i]);
        }
        else{
            printf("%c",sentence[i]);
        }
        
    }
    printf("\n");

}


void count_greater(int numbers[])
{
    /* WRITE YOUR CODE HERE */
    int length = 0;
    int i;
    int t;
    int count = 0;
    while (numbers[length] != '\0') {
        length++;
    }
    for(i = 0; i<length;i++){
        for(t = 0; t<length;t++){
            if(numbers[t] < numbers[i]){
                count++;
            }
        }
        printf("Element %d: %d\n",i, count);
        count = 0;
    }
}


void reverse_capitalize(char sentence[]) {
    /* WRITE YOUR CODE HERE */
    int left, right,write, shift, j, start, end, i, has_hyphen, length, var;
    char temp;
    const char OFFSET = 'a' - 'A';

    i = 0;

    while (1) {
        while (sentence[i] == ' ') {
            i++;
        }

        if (sentence[i] == '\0') {
            break;
        }

        start = i;

        while (sentence[i] != ' ' && sentence[i] != '\0') {
            i++;
        }

        end = i - 1;

        has_hyphen = 0;
        for (j = start; j <= end; j++) {
            if (sentence[j] == '-') {
                has_hyphen = 1;
                break;
            }
        }

        if (has_hyphen) {
            left = start;
            right = end;
            while (left < right) {
                temp = sentence[left];
                sentence[left] = sentence[right];
                sentence[right] = temp;
                left++;
                right--;
            }

            write = start;
            for (j = start; j <= end; j++) {
                if (sentence[j] != '-') {
                    sentence[write] = sentence[j];
                    write++;
                }
            }

            shift = j - write;

            while (sentence[j] != '\0') {
                sentence[j - shift] = sentence[j];
                j++;
            }
            sentence[j - shift] = '\0';

            i = write;
            end = write - 1;

            if (sentence[start] >= 'a' && sentence[start] <= 'z') {
                sentence[start] = sentence[start] - OFFSET;
            }
        }
    }
    while (sentence[length] != '\0') {
        length++;
    }
    for(var = 0; var<length; var++){
        printf("%c",sentence[var]);
    }
    printf("\n");
}
