#include "permut.h"

/*
 * This function checks if the given word is a permutation of the given base_word string.
 * It returns the index of the first character of the permutation if it is, and -1
 * if it is not.
 */
int is_permutation(char* word, char* base_word, int base_len) {
    /* set char pointer to the start of the word */
    int index = -1;

    /* increase word to the first char in base */
    word += (index = strcspn(word, base_word));
    /* check if theres a word from base_word chars with length >= base_len, else return -1 */
    if(strspn(word, base_word) < base_len) return -1;

    /* Return the index of the first character of the permutation */
    return index;
}


/* 
 * This function finds all permutations of the given word in the given line.
 * It prints the permutations to stdout. 
*/
int find_permutations(char* line, char* base_word, int base_word_len) {
    /* set index and first token */
    int idx = 0, number_of_permutations = 0;
    char* token = strtok(line, " ");

    /* loop through tokens */
    for(; token != NULL; token = strtok(NULL, " ")) {
        /* loop through characters in token if theres still length for base */
        for (; (*token != '\0') && (strlen(token) >= base_word_len); token++) {
            /* check if token is a permutation of word */
            if((idx = is_permutation(token, base_word, base_word_len)) != -1) {
                /* print the permutation */
                fprintf(stdout, "%s\n", strndup((token += idx), base_word_len));
                number_of_permutations++;
            }
        }
    }

    return number_of_permutations;
}

int main(int argc, char* argv[]) {
    /* declare variables */
    FILE* fp;
    
    char* data = NULL;
    size_t len = 0;
    char c;
    
    char* base_word;
    int base_word_len = 0, is_empty = 1;

    /* check if the number of parameters is correct */
    if (argc != 3) {
        error("Invalid number of parameters.\n");
    }

    /* copy the base_word string from args */
    base_word_len = strlen(argv[2]);
    base_word = (char*) malloc(sizeof(char) * (base_word_len + 1));
    strcpy(base_word, argv[2]);
    
    /* open the file and catch error */
    if((fp = fopen(argv[1], "r")) == NULL) {
        error("Error opening file.\n")
    };

    /* read the file line by line */
    while((c = fgetc(fp)) != EOF) {
        /* if not space mark file as not empty */
        if (!is_empty(c)) {
            is_empty = 0;
        }
        
        /* update length */
        len++;
        /* reallocate memory and catch error */
        data = (char*) realloc(data, len);
        if(data == NULL) {
            error("Error allocating memory.\n");
        }
        /* add character to data */
        data[len - 1] = c;
    }

    /* check if file is empty */
    if (is_empty) {
        error("File is empty.\n")
    };

    /* find permutations of base_word in data */
    if(!find_permutations(data, base_word, base_word_len)) {
        fprintf(stdout, "No permutations found.\n");
    }

    /* free memory and close file */
    free(data);
    fclose(fp);

    return 0;
}
