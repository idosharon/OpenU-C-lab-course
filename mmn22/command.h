#ifndef COMMAND_HEADER
#define COMMAND_HEADER

#include <string.h>
#include "set.h"

/* == macros for program == */
#define COMMA ','

#define IS_SPACE(c) (c == ' ' || c == '\t')
#define IS_VALID(num) (MIN <= num && num <= MAX)
#define IS_DIGIT(c) ('0' <= c && c <= '9')

/* check if two strings are equal */
#define equal(str1, str2) (strcmp(str1, str2) == 0)
/* error macro */
#define error(msg) { printf("Error: %s\n", msg); return 1; }

/* consts */
#define NUMBER_OF_SETS 6
#define NUMBER_OF_COMMANDS 7

/* type of command */
typedef enum {
    NONE,
    DEBUG,
    READ,
    WRITE
} type;

/* union of all possible functions */
typedef union {
    void (*write)(set*, set*, set*);
    void (*read)(set*, int*, int);
    void (*debug)(set*);
    void (*none)(void);
} dynamic_function;

/* struct of command */
typedef struct {
    char* name;
    type command_type;
    int num_of_sets; /* number of sets each command needs */
    dynamic_function func;
} command;

const command* to_command(char*);
set* to_set(char*);

int execute_line(char*);

/* extren array of known sets and commands - declared in main program */
extern set sets[NUMBER_OF_SETS];
extern const command set_commands[NUMBER_OF_COMMANDS];

#endif
