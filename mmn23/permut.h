#ifndef PERMUT_HEADER
#define PERMUT_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define is_empty(c) (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\0')

#define ERROR_CODE 1
#define perror(msg) fprintf(stderr, msg)
#define error(msg) { perror(msg); \
                   exit(ERROR_CODE); }

int is_permutation(char*, char*, int);
int find_permutations(char*, char*, int);

#endif
