#include "questions.h"
#include <string.h>

char* merge_with_delims(const char **tokens, int token_count, const char **delimiters)
{
    /* YOUR CODE GOES HERE */
    int i, total_length;
    char* result;

    if (tokens == NULL || delimiters == NULL || token_count <= 0){
        return NULL;
    }

    total_length = 0;
    for (i = 0; i < token_count; ++i)
    {
        total_length += strlen(tokens[i]);
        total_length += strlen(delimiters[i]);
    }

    result = (char*) malloc((total_length + 1) * sizeof(char));
    if (result == NULL){ return NULL;}

    result[0] = '\0';

    for (i = 0; i < token_count; ++i)
    {
        strcat(result, tokens[i]);
        strcat(result, delimiters[i]);
    }

    return result;
}