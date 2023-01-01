#include "command.h"

const command set_commands[] = {
    {"union_set", SET_MANIPULATION, {&union_set}}, 
    {"intersect_set", SET_MANIPULATION, {&intersect_set} }, 
    {"sub_set", SET_MANIPULATION, {&sub_set} }, 
    {"symdiff_set", SET_MANIPULATION, {&symdiff_set} }, 
    {"print_set", SET_COMMAND, {.set_command={&print_set}} }, 
    {"read_set", SET_COMMAND, {.set_command={.list_argument=&read_set}} }, 
    {"stop", PROGRAM, {.program=&stop} },
    {"amitai_set", SET_MANIPULATION, {.set_manipulation=&amitai_set} }
};

const command* to_command(char* str) {
    int i = 0;
    for (; i < LENGTH(set_commands); i++) {
        if (equal(str, set_commands[i].value)) return &set_commands[i];
    }
    return NULL;
}
set* to_set(char* str) {
    int i = 0;
    for (; i < LENGTH(sets); i++) {
        if (equal(str, sets[i].name)) return &sets[i];
    }
    return NULL;
}


static void clean_spaces(char* str) {
    char *p = str;
    char *q = str;
    for (; *p != '\0'; p++)
    {
        if (IS_SPACE(*p)) continue;
        else *q++ = *p;
    }
    *q++ = '\0';
}

int exec(char* str) {
    /* init variables */
    char *p = str;
    const command* command;
    set** sets_args;
    set* current_grp = NULL;
    char* argument;
    int i = 0;
    int* _args;
    int len = 0;

    /* skip spaces before command */
    while (IS_SPACE(*str) && *str != '\0') str++;

    /* get command */
    for (; (!IS_SPACE(*p) && *p != '\0'); p++);

    /* duplicate command from string */
    command = to_command(strndup(str, p-str));
    if (command == NULL) error("Undefined command name");

    /* skip spaces */
    clean_spaces(p);

    sets_args = (set**) malloc(command->command_type*sizeof(set*));

    for (; i < command->command_type; i++)
    {
        argument = NEXT_TOKEN(i, p);

        if (argument == NULL) error("Missing parameter");
        
        current_grp = to_set(argument);

        if (current_grp == NULL) error("Undefined set name");
        
        sets_args[i] = current_grp;
    }

    _args = (int*) malloc(0);
    
    if(command->command_type == SET_COMMAND) {
        int num = 0;
        char* token;

        while((num = atoi((token = strtok(NULL, COMMA)) == NULL ? "-1" : token)) != -1) {
            if(!is_valid(num)) error("Invalid set member - value out of range");

            _args[len] = num;
            _args = (int*) realloc(_args, ++len);
        };

        if (token == NULL && len != 0) {
            error("List of set members is not terminated correctly");
        }
    }

    if((p[strlen(p)-1] == COMMA[0]) || (NEXT_TOKEN(i, p) != NULL)) error("Extraneous text after end of command");

    switch (command->command_type)
    {
        case PROGRAM:
            command->func.program();
            break;
        case SET_COMMAND:
            command->func.set_command.list_argument(sets_args[0], _args, len);
            break;
        case SET_MANIPULATION:
            command->func.set_manipulation(sets_args[0], sets_args[1], sets_args[2]);
            break;
    }
    
    return 0;
}
