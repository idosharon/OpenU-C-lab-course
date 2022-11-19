#include <stdio.h>
#include "abc.h"
#include "shorten.h"

int main(int argc, char *argv[])
{
    /* set string size to MAXLEN = 80 */
    char str[MAXLEN];
    /* read string from redirection */
    fgets(str, MAXLEN, stdin);
    /* before shorten */
    printf("Before: %s\n", str);
    /* shorten string */
    shorten(str);
    /* after shorten */
    printf("After: %s\n", str);
}
