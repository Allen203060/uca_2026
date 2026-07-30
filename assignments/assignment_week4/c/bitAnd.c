#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Custom operator: AND -> %d\n", bitAnd(6, 5));
}