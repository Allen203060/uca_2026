#include <stdio.h>

int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xFF;
}

int main() {
    int x, n;
    scanf("%i %i", &x, &n);
    printf("Bytes :-> 0x%02X\n", getByte(x, n));
}
