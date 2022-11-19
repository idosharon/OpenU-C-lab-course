#include "shorten.h"
#include <stdio.h>

/*
    shifting string from end to start.
    e.g. shift_str("abcdef", 2, 4) => "abef"
    input: str, start index, end index
*/
void shift_str(char *str, int start, int end)
{
    /* copy letters from start to end */
    while (str[start - 1] != '\0')
        str[end++] = str[start++];
}

/*
    shorten string by removing all consecutive letters.
    e.g. shorten("abcdefABC") => "a-fA-C"
    input: string must be null-terminated.
*/
void shorten(char *str)
{
    /* initialize variables */
    int i = 0, j = 0;

    /* if the string is empty, return */
    if (str[0] == '\0')
        return;

    /* loop through the string */
    for (; str[i] != '\0'; i++)
    {
        /* if current character is letter and next letter is consecutive to current */
        if (IS_LETTER(str[i]) && CHECK_DIFF(str[i + 1], str[i]))
        {
            /* set j to the current character */
            j = i;

            /* loop through the string until the next character is not consecutive to current character */
            for (; str[j + 1] != '\0' && IS_LETTER(str[j + 1]) && CHECK_DIFF(str[j + 1], str[j]); j++)
                ;
            
            /* found sequence of 3 or more consecutive letters */
            if (j - i > 1) {
                /* set next char in string to '-' */
                str[i + 1] = '-';

                /* shift the string to the left to remove the middle sequence letters */
                shift_str(str, j, i + 2);
            }
        }
    }
}
