#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack DataStructure
typedef struct {
    int top; 
    int *data;
    int capacity;
} Stack;

void init(Stack *st, int capacity) {
    st->capacity = capacity;
    st->top = -1;
    st->data = (int *)malloc(capacity * sizeof(int));
}

void push(Stack *st, int val) {
    if (st->top == st->capacity - 1) {
        st->capacity *= 2;
        st->data = (int *)realloc(st->data, st->capacity * sizeof(int));
    }
    st->data[++st->top] = val;
}

int pop(Stack *st) {
    if (st->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return st->data[st->top--];
}

int evalPostFix(char *expr) {
    Stack st;
    init(&st, 20);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch >= '0' && ch <= '9') {
            push(&st, (ch - '0'));
        } 
        else {
            int e2 = pop(&st);
            int e1 = pop(&st);
            switch (ch) {
                case '+':
                    push(&st, (e1 + e2));
                    break;
                
                case '-':
                    push(&st, (e1 - e2));
                    break;

                case '*':
                    push(&st, (e1 * e2));
                    break;

                case '/':
                    if (e2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&st, (e1 / e2));
                    break;
                
                default:
                    continue;
            }
                 
        }
    }
    int res = pop(&st);
    free(st.data);
    return res;
}


int main() {
    char expr[100];

    printf("Enter postfix expression: ");
    scanf("%s", expr);

    int result = evalPostFix(expr);

    printf("Result = %d\n", result);

    return 0;
}