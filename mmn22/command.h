#ifndef COMMAND_HEADER

#define COMMAND_HEADER
#include "set.h"
#include <string.h>

#define COMMA ","
#define IS_SPACE(c) (c == ' ' || c == '\t')
#define is_valid(num) (0 <= num && num < MAX)
#define NEXT_TOKEN(i, p) strtok((i == 0 ? p : NULL), COMMA)
#define equal(str1, str2) (strcmp(str1, str2) == 0)
#define error(msg) { printf("Error: %s\n", msg); return 1; }

int exec(char*);

typedef enum {
    /* number of sets arguments */
    PROGRAM,
    SET_COMMAND,
    SET_MANIPULATION = 3
} type;

typedef union {
    void (*no_arguments)(set*);
    void (*list_argument)(set*, int*, int);
} set_command;

typedef union {
    void (*set_manipulation)(set*, set*, set*);
    set_command set_command;
    void (*program)(void);
} dynamic_function;

typedef struct {
    char* value;
    type command_type;
    dynamic_function func;
} command;

#endif
