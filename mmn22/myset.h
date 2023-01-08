#ifndef MYSET_HEADER
#define MYSET_HEADER

#include "command.h"

/* check if string is only made of spaces */
#define is_empty(str) (strspn(str, " \t\n") == strlen(str))

#endif
