#ifndef SET_HEADER
#define SET_HEADER

#include <stdio.h>
#include <stdlib.h>

/* 0-127 */
#define MIN 0
#define MAX 127

/* typedef one byte data type */
typedef char byte;

/* len = number of bytes in optimal set array */
#define BITS_PER_BYTE (sizeof(byte) * 8)
#define SET_LEN ((MAX - MIN + 1) / BITS_PER_BYTE)

/* set struct */
typedef struct {
    char* name;
    byte arr[SET_LEN];
} set;

/* set related functions */
int to_index(int);
byte to_mask(int);
byte is_in_group(set*, int);
void insert(set*, int);

void read_set(set*, int*, int);
void print_set(set*);
void union_set(set*, set*, set*);
void intersect_set(set*, set*, set*);
void sub_set(set*, set*, set*);
void symdiff_set(set*, set*, set*);
void stop(void);

#endif
