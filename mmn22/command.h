#ifndef COMMAND_HEADER

#define COMMAND_HEADER

#include "set.h"
#include <string.h>

/* macros for program */
#define IS_SPACE(c) (c == ' ' || c == '\t')
#define IS_VALID(num) (MIN <= num && num <= MAX)
#define IS_DIGIT(c) ('0' <= c && c <= '9')
#define LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#define NUMBER_OF_COMMANDS 7

#define equal(str1, str2) (strcmp(str1, str2) == 0)
#define error(msg) { printf("Error: %s\n", msg); return 1; }

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
    char* name;
    type command_type;
    int num_of_sets;
    dynamic_function func;
} command;

const command* to_command(char*);
set* to_set(char*);

int exec(char*);

extern const command set_commands[NUMBER_OF_COMMANDS];

#endif
