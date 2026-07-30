#include <stdio.h>

int bitXOR(int x, int y) {
return ~(~x & ~y) & ~(x & y);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Custom operator: AND -> %d\n", bitXOR(x, y));
}