#include "rottate.h"
#include <stdio.h>

/* number of bits in an unsigned int for current machine */
static const int NUM_OF_BITS = 8 * sizeof(unsigned int);

/*
    rotate bits in a number to the left or right by b bits.
    e.g. my_rottate(0b10101010, 2) => 0b10000000000000000000000000101010
    input: a (unsigned int) - number to rotate, b (int) - number of bits to rotate
*/
unsigned int my_rottate(unsigned int a, int b) {
    /* init variables: i - index, pow - place of rotated bit */
    short int i = 0, pow = NUM_OF_BITS - 1;
    /* number of bits to rotate */
    int num_of_rotates = ((b < 0) ? -b : b);
    /* mask for rotated bit */
    unsigned int mask = (b > 0) ? 1 : (1 << (pow)), bit;
    
    /* loop through the number of bits to rotate */
    for (; i < num_of_rotates; i++) {
        /* get rotated bit using bitwise AND with mask */
        bit = a & mask;
        /* shift the bit to the most left or most right place depending on b */
        bit = (b < 0) ? (bit >> pow) : (bit << pow);
        /* shift the number to the left or right depending on b making room for the rotated bit */
        a = (b < 0) ? a << 1 : a >> 1;
        /* add the rotated bit to the number */
        a += bit;
    }

    /* return the rotated number */
    return a;
}

/*
    print compare betwee two numbers in all bases
*/
void printCompareAllBases(unsigned int before, unsigned int after) {
    /* print before and after in decimal */
    printf("base 10 (decimal): %u -> %u\n", before, after);
    /* print before and after in hex */
    printf("base 16 (hex): %x -> %x\n", before, after);
    /* print before and after in octal */
    printf("base 8 (octal): %o -> %o\n", before, after);
    /* print before and after in binary */
    printf("base 2 (binary): ");
    printb(before, NUM_OF_BITS);
    printf(" -> ");
    printb(after, NUM_OF_BITS);
    printf("\n");
}

/*
    print number in binary
    input: number, number of bits
*/
void printb(unsigned int number, int num_digits) {
    int digit;
    /* print the number in binary */
    for(digit = num_digits - 1; digit >= 0; digit--) {
        /* print the binary digit using bitwise AND */
        printf("%c", number & (1 << digit) ? '1' : '0');
    }
}
