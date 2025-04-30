#include <stdlib.h>


char** split(char *str, char delimiter) {
    /* WRITE YOUR CODE HERE */
    int i;
    int count;
    int start;
    int rows;
    int length;
    char **result; /* pointer to first element. of the pointer array as in *arr[] then **result = *arr;*/

    i = 0;
    count = 1; /* in question it is specified that we should always have min(1,count)*/
    while (str[i] != '\0') {
        if (str[i] == delimiter) {
            count++;/*how many partitions to make*/
        }
        i++;
    }

    /* pointer to char pointers array memory allocated with +1 for null. */
    result = (char**)malloc((count + 1) * sizeof(char*));
    if (result == NULL) {
        return NULL;
    }

    /*string split operation*/
    start = 0;/* start for each substring related with i count.*/
    rows = 0;/* Rows that each substring are in.*/
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == delimiter) {
            int columns;
            length = i - start; /* length of the substring*/

            result[rows] = (char*)malloc((length + 1) * sizeof(char));
            if (result[rows] == NULL) {
                int k;
                for (k = 0; k < rows; k++) {
                    free(result[k]); /* if null free dynamically allocated memory*/
                }
                free(result);
                return NULL;
            }

            for (columns = 0; columns < length; columns++) {
                result[rows][columns] = str[start + columns]; /* think substring as array of chars and at each row we have many columns that has 1 char.*/
            }
            result[rows][length] = '\0';

            rows++;
            start = i + 1;
        }
        i++;
    }

    /* last delimiter, can be whole part as well if no delimiter.*/
    length = i - start;
    if (length > 0 || (i > 0 && str[i - 1] != delimiter)) {
        int j;
        result[rows] = (char*)malloc((length + 1) * sizeof(char));
        if (result[rows] == NULL) {
            int k;
            for (k = 0; k < rows; k++) {
                free(result[k]); /* row freed char pointers*/
            }
            free(result);
            return NULL;
        }
        for (j = 0; j < length; j++) {
            result[rows][j] = str[start + j];
        }
        result[rows][length] = '\0';
        rows++;
    }

    /* finish NULL.*/
    result[rows] = NULL;

    return result;
}
