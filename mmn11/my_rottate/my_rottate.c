#include <stdio.h>
#include "my_rottate.h"
#include <wchar.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    // unsigned int a = 32922;
    // short int shift = -3;
    // printf("number = %d, shift = %d:\n", a, shift);
    setlocale(LC_CTYPE, "");
    wchar_t flag = 0x2691;
    wprintf(L"%lc\n", flag);
    // printCompareAllBases(a, my_rottate(a, shift), NUM_OF_BITS);
    return 0;
}

void printCompareAllBases(unsigned int before, unsigned int after, int num_digits) {
    // print before and after in decimal
    printf("base 10: %d -> %d\n", before, after);
    // print before and after in hex
    printf("base 16: %x -> %x\n", before, after);
    // print before and after in octal
    printf("base 8: %o -> %o\n", before, after);
    // print before and after in binary
    printf("base 2: ");
    printb(before, num_digits);
    printf(" -> ");
    printb(after, num_digits);
    printf("\n");
}

void printb(unsigned int number, int num_digits) {
    int digit;
    // print the number in binary
    for(digit = num_digits - 1; digit >= 0; digit--) {
        // print the binary digit using bitwise AND
        printf("%c", number & (1 << digit) ? '1' : '0');
    }
}

unsigned int my_rottate(unsigned int a, int b) {
    short int i = 0, pow = NUM_OF_BITS-1;
    unsigned int mask = (b > 0) ? 1 : (1 << (NUM_OF_BITS-1)), temp;
    
    for (; i < ((b < 0) ? -b : b); i++) {
        temp = a & mask;
        temp = (b < 0) ? (temp >> pow) : (temp << pow);
        a = (b < 0) ? a << 1 : a >> 1;
        a += temp;
    }

    return a;
}
