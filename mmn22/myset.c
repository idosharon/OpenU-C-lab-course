#include "myset.h"

/* define known sets and commands */
set sets[] = {{"SETA", {0}}, {"SETB", {0}},
              {"SETC", {0}}, {"SETD", {0}},
              {"SETE", {0}}, {"SETF", {0}}};

const command set_commands[] = {
    {"union_set", WRITE, 3, {&union_set}}, 
    {"intersect_set", WRITE, 3, {&intersect_set} }, 
    {"sub_set", WRITE, 3, {&sub_set} }, 
    {"symdiff_set", WRITE, 3, {&symdiff_set} }, 
    {"print_set", DEBUG, 1, {.debug=&print_set} }, 
    {"read_set", READ, 1, {.read=&read_set} }, 
    {"stop", NONE, 0, {.none=&stop} }
};

/* == main function == */
int main(int argc, char* argv[]) {
    /* file pointer */
    FILE *fp;
    /* current line */
    char* line = NULL;
    /* line number */
    int file_index = 1, line_number = 1;

    /* length of line */
    size_t len = 0;

    /* check if no file was given */
    if(argc == 1) {
        error("No files were given.");
    }

    /* iterate through all input parameters */
    for(; file_index < argc; file_index++) {
        /* get current file name from argv */
        char* file_name = argv[file_index];

        printf("== %s ==\n", file_name);

        /* open file */
        fp = fopen(file_name, "r");
        if (fp == NULL) {
            printf("Error: Could not open file: %s", file_name);
            return 1;
        }
        
        /* read lines */
        while (getline(&line, &len, fp) != -1) {
            /* check if entire line is spaces */
            if (is_empty(line)) continue;
            /* set null terminator if needed */
            if (line[strlen(line) - 1] == '\n') 
                line[strlen(line) - 1] = '\0';

            /* exec line */
            printf(">> %s\n", line);
            if (execute_line(line)) {
                printf("Program exited with an error on line: %d\n", line_number);
                return 1;
            };

            /* increment line number */
            line_number++;
        }

        fclose(fp);
    }

    free(line);

    return 0;
}
