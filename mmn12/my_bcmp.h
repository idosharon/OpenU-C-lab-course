#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 512

#define ERR_PREFIX "[error]"
#define ERROR(msg) { printf(ERR_PREFIX ": %s\n", msg); exit(1); }
#define ERROR_VAL(msg, val) { printf(ERR_PREFIX ": %d - %s\n", val, msg); exit(1); }

int my_bcmp (const void *b1, const void *b2, int len);
typedef unsigned char byte;
