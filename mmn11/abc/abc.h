#define MAXLEN 80
#define printd(x, y) printf("%d - %d\n", x, y)
#define IS_ABC(c) (((97 <= c) && (c <= 122)) || ((65 <= c) && (c <= 90)) ? 1 : 0 )

void shift_str(char* str, int start, int end);
void shorten(char* str);