#ifndef COMMAND_HEADER

#define COMMAND_HEADER
#include "set.h"
#include <string.h>

#define COMMA ","
#define IS_SPACE(c) (c == ' ' || c == '\t')
#define IS_VALID(num) (0 <= num && num < MAX)
#define IS_DIGIT(c) ('0' <= c && c <= '9')

#define skip_spaces(str) while (IS_SPACE(*str)) str++;

#define equal(str1, str2) (strcmp(str1, str2) == 0)
#define error(msg) { printf("Error: %s\n", msg); return 1; }

int exec(char*);

typedef enum {
    /* number of sets */
    NONE,
    DEBUG,
    READ,
    WRITE
} type;

typedef union {
    void (*write)(set*, set*, set*);
    void (*read)(set*, int*, int);
    void (*debug)(set*);
    void (*none)(void);
} dynamic_function;

typedef struct {
    char* value;
    type command_type;
    int num_of_sets;
    dynamic_function func;
} command;

#endif
