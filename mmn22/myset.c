#include "myset.h"

set sets[] = {{"SETA", {0}}, {"SETB", {0}}, 
              {"SETC", {0}}, {"SETD", {0}},
              {"SETE", {0}}, {"SETF", {0}}};

int main(int argc, char* argv[]) {
    char* file_name = argv[1];

    /* read file line by line */
    FILE *fp = fopen(file_name, "r");
    char line[MAXLEN];

    while (fgets(line, MAXLEN, fp)) {
        /* clean line */
        if(equal(line, "\n")) continue;
        if (line[strlen(line) - 1] == '\n') line[strlen(line) - 1] = '\0';
        /* exec line */
        printf(">> %s\n", line);
        exec(line);
    }


    return 0;
}
