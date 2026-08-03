#include <stdio.h>

int logicalShift(int x, int n) {

  int messy_shift = x >> n;
  int mask = ~(((1 << 31) >> n) << 1);

  return messy_shift & mask;
}

int main() {
    int x, n;
    scanf("%i %i", &x, &n);
    printf("Logical Shift :-> 0x%08X\n", logicalShift(x, n));
}
