#include <stdio.h>

typedef enum {
    NORMAL,
    IN_STRING,
    IN_CHAR,
    IN_BLOCK_COMMENT,
    IN_LINE_COMMENT
} State;

int main() {
    int c, next_c;
    State state = NORMAL;

    while ((c = getchar()) != EOF) {
        switch (state) {
            case NORMAL:
                if (c == '/') {
                    next_c = getchar();
                    if (next_c == '*') {
                        state = IN_BLOCK_COMMENT;
                    } else if (next_c == '/') {
                        state = IN_LINE_COMMENT;
                    } else {
                        putchar(c);
                        if (next_c != EOF) ungetc(next_c, stdin);
                    }
                } else if (c == '"') {
                    putchar(c);
                    state = IN_STRING;
                } else if (c == '\'') {
                    putchar(c);
                    state = IN_CHAR;
                } else {
                    putchar(c);
                }
                break;

            case IN_STRING:
                putchar(c);
                if (c == '\\') {
                    next_c = getchar();
                    if (next_c != EOF) putchar(next_c);
                } else if (c == '"') {
                    state = NORMAL;
                }
                break;

            case IN_CHAR:
                putchar(c);
                if (c == '\\') {
                    next_c = getchar();
                    if (next_c != EOF) putchar(next_c);
                } else if (c == '\'') {
                    state = NORMAL;
                }
                break;

            case IN_BLOCK_COMMENT:
                if (c == '*') {
                    next_c = getchar();
                    if (next_c == '/') {
                        state = NORMAL;
                    } else {
                        if (next_c != EOF) ungetc(next_c, stdin);
                    }
                }
                break;

            case IN_LINE_COMMENT:
                if (c == '\n') {
                    putchar(c);
                    state = NORMAL;
                }
                break;
        }
    }

    return 0;
}