#ifndef PERMUT_HEADER
#define PERMUT_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define is_empty(str) (strspn(str, " \t\n\r") == strlen(str))

#define ERROR_CODE 1
#define perror(msg) fprintf(stderr, msg)
#define error(msg) perror(msg); \
                   exit(ERROR_CODE);

typedef struct node {
    char* value;
    struct node* next;
} node;

#define is_empty_list(head) (head == NULL)
#define has_next(node) (node->next != NULL)


node* find_permutations(char* str, char* word);

#endif
