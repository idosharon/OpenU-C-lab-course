#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX 128 /* 0-127 */
#define is_valid(num) (0 <= num && num < MAX)
#define NUMBER_OF_SETS 6
#define LENGTH(arr) (sizeof(arr) / sizeof(arr[0]))

#define get_element(num, idx, mask) \
    int idx = to_index(num);        \
    byte mask = to_mask(num);

typedef char byte;
#define BITS_PER_BYTE (sizeof(byte) * 8)
#define LEN (MAX)/(BITS_PER_BYTE)

typedef struct {
    char* name;
    byte arr[LEN];
} set;

extern set sets[NUMBER_OF_SETS];

void printb(unsigned int, int);

int to_index(int);
void insert(set*, int);
byte find(set*, int);

void read_set(set*, int*, int);
void print_set(set*);
void union_set(set*, set*, set*);
void intersect_set(set*, set*, set*);
void sub_set(set*, set*, set*);
void symdiff_set(set*, set*, set*);
void stop(void);
