#include "questions.h"
#include <string.h>

/*  ADD HELPER FUNCTIONS IF NEEDED */
char* copy_token(const char* start, int len)
{
    char* token = (char*) malloc((len + 1) * sizeof(char));
    if (token == NULL){ return NULL;}

    strncpy(token, start, len); /*copy and then we add the '\0' */
    token[len] = '\0'; /* null terminate*/
    return token;
}

char** split_string(const char *str, const char delim, int *token_count)
{
    /* YOUR CODE GOES HERE  */
    char** result;
    int i, start, count, len;
    char* token;
    char** temp;

    if (str == NULL || token_count == NULL) return NULL;

    result = NULL;
    i = 0;
    start = 0;
    count = 0;
    len = strlen(str);

    /* Do not process last delimiter if at the end of string */
    if (len > 0 && str[len - 1] == delim)
        len--;

    for (i = 0; i <= len; ++i)
    {
        if (str[i] == delim || i == len)
        {
            token = copy_token(str + start, i - start);

            temp = (char**) realloc(result, (count + 1) * sizeof(char*));
            if (temp == NULL) return NULL;

            result = temp;
            result[count] = token;
            count++;
            start = i + 1;
        }
    }

    *token_count = count;
    return result;
}