#include "my_bcmp.h"

int main (int argc, char *argv[]) {
    char *str = "Hello, world! Hello, nice.";
    char* p1 = &str[0];
    char* p2 = &str[14];
    // TODO: check if input is valid

    printf("%s\n", (my_bcmp(p1, p2, 5) ? "Not same" : "same strings"));
    
    return 0;
}

int my_bcmp (const void *b1, const void *b2, int len) {
    byte *p1 = (byte*)b1;
    byte *p2 = (byte*)b2;
    while(len-- > 0) {
        if (*(p1++) != *(p2++)) return 1;
    }
    return 0;
}
