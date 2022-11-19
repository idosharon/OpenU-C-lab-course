#include <stdio.h>
#include "rottate.h"

int main(int argc, char const *argv[])
{
    /* init variables */
    unsigned int num;
    int shift;
    /* read input from user */
    printf("Enter a number in decimal: ");
    scanf("%u", &num);
    printf("Enter number of bits to rotate: ");
    scanf("%d", &shift);
    /* print num and shift */
    printf("# num: %u, shift: %d #\n", num, shift);
    /* print compare between before and after */
    printCompareAllBases(num, my_rottate(num, shift));
    
    return 0;
}
