#include <stdlib.h>
#include <stdio.h>

int mergeAndCount(int arr[], int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while(j <= right && (long long) arr[i] > arr[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    int *temp = (int*)malloc((right - left + 1) * sizeof(int));
    int i = left, k = 0;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);

    return count;

}

int mergeSortAndCount(int arr[], int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left)/2;
    int count = 0;

    count += mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;

}

int countInversion(int arr[], int size) {
    if (size == 0) return 0;
    return mergeSortAndCount(arr, 0, size-1);
}

int main() {
    //int arr[] = {1, 2, 4, 1, 3, 5};
    int arr[] = {2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int answer = countInversion(arr, size);

    printf("The inversion count is %d\n", answer);
}