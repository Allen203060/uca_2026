#include <stdio.h>

int find(int arr[], int n) {
    int ans = 0;
    for (int bitIdx = 0; bitIdx < 32; bitIdx++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if ((arr[i] & (1 << bitIdx)) != 0) {
                count++;
            }
        }
        if (count % 3 != 0) ans ^= (1 << bitIdx);
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
    int output = find(arr, sizeof(arr)/sizeof(int));
    
    printf("The number that appears 4 times is %d\n", output);
}