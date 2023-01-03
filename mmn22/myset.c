#include "myset.h"

const set sets[] = {{"SETA", {0}}, {"SETB", {0}},
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

int main(int argc, char* argv[]) {
    char* file_name = argv[1];

    /* read file line by line */
    FILE *fp = fopen(file_name, "r");
    char line[MAXLEN];
    char* line_p = line;
    int line_index = 0;

    while (fgets(line, MAXLEN, fp)) {
        line_index++;
        line_p = line;

        /* clean line */
        for(; *line_p != '\0' && IS_SPACE(*line_p); line_p++);
        if(*line_p == '\n') continue;
        if (line_p[strlen(line_p) - 1] == '\n') line_p[strlen(line_p) - 1] = '\0';
        /* exec line */
        printf(">> %s\n", line_p);
        if (exec(line_p)) {
            printf("Program exited with an error on line: %d\n", line_index);
            return 1;
        };
    }
    
    fclose(fp);
    return 0;
}
