#include "command.h"

/* to_command: find the command in global commands from string
    str - command name to search in str
    return - command pointer to the corresponding 
             command with same name as str, 
             NULL if none was found. */
const command* to_command(char* str) {
    int i = 0;
    for (; i < NUMBER_OF_COMMANDS; i++) {
        if (equal(str, set_commands[i].name)) 
            return &set_commands[i];
    }
    return NULL;
}

/* to_set: find the set in global sets from string
    str - set name to search in str
    return - set pointer to the corresponding 
             set with same name as str, 
             NULL if none was found. */
set* to_set(char* str) {
    int i = 0;
    for (; i < NUMBER_OF_SETS; i++) {
        if (equal(str, sets[i].name)) 
            return &sets[i];
    }
    return NULL;
}

/* next_token: improved version for strtok 
        - split string to tokens by delimiter
    str - pointer to pointer string to update each call; 
          first time use start of string, 
          else NULL to continue from last call place
    delimiter - delimiter to split by
*/
static char* next_token(char** str, char delimiter) {
    /* set static variables for pointer and original string pointer */
    static char* p;
    static char** str_p;
    char c;

    /* if first time set static variables */
    if (str != NULL) {
        str_p = str;
        p = *str_p;
    } else {
        /* else, update original string to last token's end */
        *str_p = p;
    };

    /* search end of new token */
    for(; (c = *p++) != '\0' && c != delimiter;);

    /* return end of found token */
    return p;
}

/* clean_spaces: clean spaces from given string
    str - string
    return - number of 'words' (non-space chunks) found in string */
static int clean_spaces(char* str) {
    /* set pointers to string */
    char *p = str;
    char *q = str;
    /* counter of 'words' */
    int counter = 0;
    /* flag if reached space */
    int flag = 1;
    /* iterate over string */
    for (; *p != '\0'; p++)
    {
        if (IS_SPACE(*p)) {
            /* read space, set flag and continue - don't copy */
            flag = 1;
            continue;
        } else {
            /* read non-space, copy and update counter */
            *q++ = *p;
            counter += flag;
            /* reset flag */
            flag = 0;
        };
    }

    /* add null terminator */
    *q++ = '\0';
    return counter;
}

/* contains: check if string contains char
    str - string
    c - char
    return - 1 if contains, 0 if not */
static int contains(char* str, char c) {
    char* p = str;
    for (; *p != '\0'; p++) {
        if (*p == c) return 1;
    }
    return 0;
}

/* is_number: checks if a given string is an int number
    str - string
    return -  1 if str is an int number, 0 if not */
static int is_number(char* str) {
    /* check for sign */
    if(*str == '-' || *str == '+') str++;

    /* check for digits */
    for (; *str != '\0'; str++) {
        if (!IS_DIGIT(*str)) return 0;
    }
    
    return 1;
}

/* execute_line: execute a line of code
    str - line to execute as string
    return - 0 if no error, 1 if error
*/
int execute_line(char* str) {
    /* == DEFS == */

    /* get first token */
    char* p = NULL;

    /* command pointer and get command name */
    const command* current_command;
    set* current_set;

    /* command name as string */
    char* command_name;
    
    /* init list of sets arguments */
    set** sets_args;

    /* init number array for  */
    int* arr = (int*) malloc(sizeof(int));
    int len = 0, current_num = 0, error = 0;

    /* current set and num strings for loops */
    char* set_str;
    char* num_str;

    /* == START OF CODE == */
    
    /* clean line from first spaces */
    for(; *str != '\0' && IS_SPACE(*str); str++);
            
    /* get command name */
    for(p = str; !IS_SPACE(*p); p++);
    for(; IS_SPACE(*p) || *p == COMMA; p++);

    command_name = strndup(str, p - str);
    
    /* clean spaces from command name */
    clean_spaces(command_name);

    /* check for illegal comma */
    if(contains(command_name, COMMA)) error("Illegal comma");

    /* get command pointer */
    current_command = to_command(command_name);
    if (current_command == NULL) error("Undefined command name");

    /* update string to end of command name */
    str = p;

    /* create empty list of sets with size command->type_Command */
    sets_args = (set**) malloc(sizeof(set*) * current_command->num_of_sets);
    
    /* for each set in the current command's num of sets */
    for (; len < current_command->num_of_sets;)
    {
        /* get next token */
        p = next_token(len == 0 ? &str : NULL, COMMA);

        if (*str == '\0') error("Missing parameter");

        /* get set name */
        set_str = strndup(str, p - str - 1);
        
        /* clean spaces from set name */
        error = clean_spaces(set_str);
        
        /* check for errors */
        if (error == 0) { error("Multiple consecutive commas"); }
        else if (error > 2) error("Missing comma");
        
        /* get current set pointer */
        current_set = to_set(set_str);
        if (current_set == NULL) error("Undefined set name");

        /* add to array */
        sets_args[len++] = current_set;
    }

    /* check for read command */
    if (current_command->command_type == READ) {
        len = 0;
        
        while(1)
        {
            /* get next token */
            p = next_token(NULL, COMMA);

            /* get string of num */
            num_str = strndup(str, p - str - 1);

            /* clean spaces from num string */
            error = clean_spaces(num_str);
            
            /* break if reached end */
            if(*num_str == '\0') break;

            /* check for errors */        
            if (error == 0) { error("Multiple consecutive commas"); }
            else if (error > 2) error("Missing comma");
            
            /* check number */
            if(!is_number(num_str)) error("Invalid set member - not an integer");
            
            /* convert to int */
            current_num = atoi(num_str);
            
            /* if reached -1 break */
            if (current_num == -1) break;

            /* check if in range */
            if(!IS_VALID(current_num)) error("Invalid set member - value out of range"); 

            /* add to array */
            arr[len++] = current_num;

            /* resize array with new length */
            arr = realloc(arr, len);
        }

        /* check if last num is -1 */
        if (current_num != -1) error("List of set members is not terminated correctly");
    };
    
    /* check for extraneous text */
    if (!(IS_SPACE(*(p-1)) || *(p-1) == '\n' || *(p-1) == '\0')) error("Extraneous text after end of command");

    /* execute command */
    switch(current_command->command_type) {
        case READ:
            current_command->func.read(sets_args[0], arr, len);
            break;
        case WRITE:
            current_command->func.write(sets_args[0], sets_args[1], sets_args[2]);
            break;
        case DEBUG:
            current_command->func.debug(sets_args[0]);
            break;
        case NONE:
            current_command->func.none();
            break;
    }

    /* free memory */
    free(sets_args);
    free(arr);
    
    return 0;
}
