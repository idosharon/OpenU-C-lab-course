#include "my_bcmp.h"

/* check if index is valid: non negative and  */
static void check_index(int index, int len, int maxlen) {
    /* check if non negative */
    if (index < 0) ERROR_VAL("Invalid index: must be non negative", index);
    /* check if in string bounds */
    if(index + len > maxlen) ERROR_VAL("Invalid index: must be in string bounds", index);
}

int main (int argc, char *argv[]) {
    /* define variables */
    char str[MAXLEN]; 
    void *p1, *p2;
    int len, idx1, idx2;
    float temp;

    /* get compare length */
    printf("Enter length to compare: ");
    
    /* check for valid input */
    if (scanf("%f", &temp) != 1 || temp != (len = (int)temp)) 
        ERROR("Invalid length: must be an integer");
    
    if (len < 0) ERROR_VAL("Invalid length: must be non negative", len);

    /* get index 1 for the compare */
    printf("Enter index 1: ");
    if (scanf("%f", &temp) != 1 || temp != (idx1 = (int)temp)) 
        ERROR("Invalid index: must be an integer");

    check_index(idx1, len, MAXLEN);

    /* get index 2 for the compare */
    printf("Enter index 2: ");
    if (scanf("%f", &temp) != 1 || temp != (idx2 = (int)temp)) 
        ERROR("Invalid index: must be an integer");

    check_index(idx2, len, MAXLEN);

    /* read string for compare test  */
    printf("Enter string: ");
    if (scanf("%s", str) != 1) ERROR("Invalid string: must be a string");

    /* move pointers to comp locations in string */
    p1 = str + idx1;
    p2 = str + idx2;

    /* compare data using my_bcmp */
    printf("Comparing %d bytes from %d to %d\n", len, idx1, idx2);
    printf("The compared data is: %s and %s\n", strndup(p1, len), strndup(p2, len));
    printf("Result: %s\n", (my_bcmp(p1, p2, len) ? "Different Bytes" : "Same Bytes"));
    
    return 0;
}

/*
    function: my_bcmp
    purpose:  compare two blocks of memory per byte
    input:    b1, b2 - pointers to the blocks of memory
              len - number of bytes to compare
    output:   0 if the blocks are the same, 1 if different
*/
int my_bcmp (const void *b1, const void *b2, int len) {
    /* define byte pointers using the typedef of byte */
    byte *p1 = (byte*)b1;
    byte *p2 = (byte*)b2;
    /* iterate len times - each byte */
    while(len-- > 0) {
        /* compare the two current bytes, return 1 if there is a different */
        if (*(p1++) != *(p2++)) return 1;
    }
    /* memory blocks are the same, return 0 */
    return 0;
}
