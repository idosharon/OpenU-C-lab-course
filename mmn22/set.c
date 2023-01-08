#include "set.h"

/* to_index: 
    num - a number 
    return - the corresponding cell index
    in the set bytes array for it's representing bit. 
*/
int to_index(int num) {
    return num / BITS_PER_BYTE;
}
/* to_mask: 
    num - a number 
    return - the corresponding byte mask for it's representing bit. */
byte to_mask(int num) {
    return (0x1 << (num % BITS_PER_BYTE));
}
/* is_in_group: 
    s - a set pointer
    num - a number 
    return - positive number if the number is in the set, 0 otherwise. 
*/
byte is_in_group(set* s, int num) {
    return (s->arr[to_index(num)] & to_mask(num));
}

/* insert: insert a number to a set
    s - a set pointer
    num - a number  
*/
void insert(set* s, int num) {
    s->arr[to_index(num)] |= to_mask(num);
}

/* read_set: read a set from an array of numbers 
             and saves it in the given set
    s - a set pointer
    arr - an array of numbers
    len - the array length
*/
void read_set(set* s, int* arr, int len) {
    int i = 0;
    /* reset the array using sub set */
    sub_set(s, s, s);
    /* for each element in array insert it into the set */
    for (; i < len; insert(s, arr[i]), i++);
}

/* union_set: C = A union B
    A - a set pointer
    B - a set pointer
    C - a set pointer
*/
void union_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < SET_LEN; C->arr[i] = (A->arr[i] | B->arr[i]), i++);
}
/* intersect_seet: C = A intersect B
    A - a set pointer
    B - a set pointer
    C - a set pointer
*/
void intersect_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < SET_LEN; C->arr[i] = (A->arr[i] & B->arr[i]), i++);
}
/* sub_set: C = A - B
    A - a set pointer
    B - a set pointer
    C - a set pointer
*/
void sub_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < SET_LEN; C->arr[i] = (A->arr[i] & !B->arr[i]), i++);
}
/* symdiff_set: C = A symdiff B
    A - a set pointer
    B - a set pointer
    C - a set pointer
*/
void symdiff_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < SET_LEN; C->arr[i] = (A->arr[i] ^ B->arr[i]), i++);
}
/* print_set: print a set
    s - a set pointer
*/
void print_set(set* s) {
    int i = 0, counter = 0;

    for (; i < MAX; i++)
    {
        if (is_in_group(s, i)) {
            printf("%d ", i);
            counter++;
            if (counter % 16 == 0) printf("\n");
        }
    }
    if(counter == 0) printf("The set is empty");
    printf("\n");
}

/* stop - stops the program */
void stop() {
    printf("Stopping program.\n");
    exit(0);
}
