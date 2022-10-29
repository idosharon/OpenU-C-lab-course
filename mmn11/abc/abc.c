#include <stdio.h>
#include <string.h>
#include "abc.h"

int main(int argc, char *argv[]) {
    char buffer[MAXLEN];
    fgets(buffer, MAXLEN , stdin);
    printf("Before: %s\n", buffer);
    shorten(buffer);
    printf("New: %s\n", buffer);
}

void shift_str(char* str, int start, int end) {
    while (str[start-1] != '\0') 
        str[end++] = str[start++];   
}

void shorten(char* str) {
    if(str[0] == '\0') return;
    
    int i = 0, j = 0;

    for (; str[i+1] != '\0'; i++)
    {
        if (str[i+1] == (str[i] + 1))
        {
            j = i;
            if(!IS_ABC(str[j])) continue;
            for(; str[i] != '\0' && str[i+1] == str[i] + 1; i++);
            if (i == j+1) continue;
            printd(j,i);
            str[j+1] = '-';
            shift_str(str, i, j+2);
            printf("%s\n", str);
        }
    }
}
