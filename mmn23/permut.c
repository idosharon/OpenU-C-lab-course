#include "permut.h"

void add(node* head, char* value) {
    node* current = head;
    for (; current->next != NULL; current = current->next);

    if (current->value != NULL) {
        current = (current->next = malloc(sizeof(node)));
    }

    current->value = value;
    current->next = NULL;
}

void print_list(node* head) {
    node* current = head;

    while (current != NULL) {
        printf("%s -> ", current->value);
        current = current->next;
    }
    printf("\n");
}

int contains(char* str, char c) {
    int counter = 0;
    for (; *str != '\0'; str++) {
        counter += (*str == c);
    }
    return counter;
}

node* find_permutations(char* line, char* word) {
    node* result = (node*) malloc(sizeof(node));
    int len = strlen(word), i = 0;
    int* char_counts;
    char* token = strtok(line, " ");

    char_counts = (int*) malloc(len * sizeof(int));
    
    for (; i < len; i++) {
        char_counts[i] = contains(word, word[i]);
    }
    
    for(; token != NULL; token = strtok(NULL, " ")) {
        token[strcspn(token, "\n")] = '\0';

        if(is_empty(token)) continue;

        i = 0;

        for(; i < len; i++) {
            if (contains(token, word[i]) != char_counts[i]) {
                break;
            }
        }

        if (i == len) add(result, strndup(token + strcspn(token, word), len));
    }

    return result;
}

int main(int argc, char* argv[]) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    node* head;
    int lines = 0;

    if (argc != 3) {
        fprintf(stderr, "Invalid number of parameters. %d\n", argc);
        return 1;
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        error("Error opening file\n")
    };

    while (getline(&line, &len, fp) != -1) {
        /* check if line is empty  */
        if (is_empty(line)) continue;
        
        lines++;

        head = find_permutations(line, argv[2]);
        for (; head != NULL && head->value != NULL; head = head->next) {
            fprintf(stdout, "%s\n", head->value);
        }
    }

    if (lines == 0) {
        error("File is empty\n")
    };

    return 0;
}
