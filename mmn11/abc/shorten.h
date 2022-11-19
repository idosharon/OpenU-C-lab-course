/* macro: check if char is a letter in abc */
#define IS_LETTER(c) ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')) ? 1 : 0)
/* define wanted diff between two following chars */
#define DIFF 1
/* macro: check if diff between two chars is equal to wanted diff */
#define CHECK_DIFF(c1, c2) ((c1 - c2 == DIFF) ? 1 : 0)

void shift_str(char *str, int start, int end);
void shorten(char *str);
