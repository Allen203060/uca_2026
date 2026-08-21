#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack DataStructure

typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

void init(Stack *s, int capacity) {
    s->capacity = capacity;
    s->top = -1;
    s->data = (char *)malloc(capacity * sizeof(char));
}

void push(Stack *st, char ch) {
    if (st->top == st->capacity - 1) {
        st->capacity *= 2;
        st->data = (char *)realloc(st->data, st->capacity * sizeof(char));
    }

    st->data[++(st->top)] = ch;
}

char pop(Stack *st) {
    if (st->top == -1) return '\0';
    return st->data[(st->top)--];
}

int isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isBalanced(char *expr) {
    Stack s;
    init(&s, 10);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } 
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.top == -1) {
                free(s.data);
                return 0;
            }
            char top = pop(&s);
            if (!isMatch(top, ch)) {
                free(s.data);
                return 0;
            }
        }
    }

    int res = (s.top == -1);
    free(s.data);
    return res;
}

int main() {
    char expr[100];  

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}