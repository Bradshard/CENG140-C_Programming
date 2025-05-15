#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <stdio.h>
#include <stdlib.h>

int* apply_permutation(int n, const int data[], const int perm[]);

int*** transpose_slices(int B, int R, int C, int ***input);

char** split_string(const char *str, const char delim, int *token_count);

char* merge_with_delims(const char **tokens, int token_count, const char **delimiters);

#endif