#include <stdio.h>
#include "my_bcmp.h"

int main (int argc, char *argv[]) {
    char *s1 = "Hello";
    char *s2 = "Hello";
    char *s3 = "World";
    printf("s1 == s2: %d\n", my_bcmp(s1, s2, 5));
    printf("s1 == s3: %d\n", my_bcmp(s1, s3, 5));
    return 0;
}

int my_bcmp (const void *b1, const void *b2, int len) {
    unsigned char *p1 = b1;
    unsigned char *p2 = b2;
    while (len-- > 0) {
        printf("p1: %hhu, p2: %hhu\n", *p1, *p2);
        if (*p1++ != *p2++) {
            return 1;
        }
    }
    return 0;
}
