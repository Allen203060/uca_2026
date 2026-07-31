#include <stdio.h>

int fitsBits(int x, int n) {
    int shift = (32-n);
    return !(((x << shift) >> shift)^x);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("FitBits :-> %d\n", fitsBits(x, y));
}