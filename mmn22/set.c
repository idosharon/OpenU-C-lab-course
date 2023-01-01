#include "set.h"

int to_index(int num) {
    return num / BITS_PER_BYTE;
}
byte to_mask(int num) {
    return (0x1 << (num % BITS_PER_BYTE));
}
byte is_in_group(set* s, int num) {
    return (s->arr[to_index(num)] & to_mask(num));
}

void insert(set* s, int num) {
    s->arr[to_index(num)] |= to_mask(num);
}
void read_set(set* s, int* arr, int len) {
    int i = 0;
    for (; i < len; insert(s, arr[i]), i++);
}
void union_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < LEN; C->arr[i] = (A->arr[i] | B->arr[i]), i++);
}
void intersect_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < LEN; C->arr[i] = (A->arr[i] & B->arr[i]), i++);
}
void sub_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < LEN; C->arr[i] = (A->arr[i] & !B->arr[i]), i++);
}
void symdiff_set(set* A, set* B, set* C) {
    int i = 0; 
    for (; i < LEN; C->arr[i] = (A->arr[i] ^ B->arr[i]), i++);
}
void amitai_set(set* A, set* B, set* C) {
    sub_set(A, B, C);
    intersect_set(A, B, A);
    union_set(A, C, C);
}
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
void stop() {
    printf("Stopping program.\n");
    exit(0);
}
