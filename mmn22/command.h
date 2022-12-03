#pragma once
#include "set.h"
#include <string.h>

#define COMMA ","
#define IS_SPACE(c) (c == ' ' || c == '\t')
#define NEXT_TOKEN(i, p) strtok((i == 0 ? p : NULL), COMMA)
#define equal(str1, str2) strcmp(str1, str2) == 0
#define error(msg) { printf("Error: %s\n", msg); return 1; }

int exec(char*);

typedef enum {
    PROGRAM,
    SET_COMMAND,
    SET_MANIPULATION = 3
} type;

typedef union {
    void (*no_arguments)(set*);
    void (*list_argument)(set*, int*, int);
} set_command;

typedef union {
    void (*program)(void);
    set_command set_command;
    void (*set_manipulation)(set*, set*, set*);
} dynamic_function;

typedef struct {
    char* value;
    type command_type;
    dynamic_function func;
} command;



