#include <stdio.h>

int isPower2(int x) {
 
  int power_test = !(x & (x + ~0));
  int is_not_zero = !!x;
  int is_positive = !(x >> 31);
  return power_test & is_not_zero & is_positive;

}

int main() {
    int x;
    scanf("%d", &x);
    printf("isPower2(%d) :-> %d\n", x, isPower2(x));
    return 0;
}