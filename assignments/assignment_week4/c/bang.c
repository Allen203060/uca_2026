#include <stdio.h>

int bang(int x) {

  return ((x | (~x + 1)) >> 31) + 1;
}

int main() {
    int x;
    scanf("%i", &x);
    printf("Bang Operator :-> %d\n", bang(x));
}
