#include <stdio.h>

int conditional(int x, int y, int z) {
    int is_zero = !x;
    int mask_z = ~is_zero + 1;
    int mask_y = ~mask_z;
    return (y & mask_y) | (z & mask_z);
}

int main() {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("Conditional :-> %d\n", conditional(x, y, z));
}
