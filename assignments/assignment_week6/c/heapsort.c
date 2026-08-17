    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void swap(void *a, void *b, size_t size) {
        void *temp = malloc(size);
        if (!temp) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        memcpy(temp, a, size);
        memcpy(a, b, size);
        memcpy(b, temp, size);

        free(temp);
    }

    void heapify(void *base, size_t n, size_t i, size_t size, int (*cmp)(const void *, const void *)) {
        size_t largest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        char *arr = (char *)base;

        if (left < n && cmp(arr + left * size, arr + largest * size) > 0) {
            largest = left;
        }

        if (right < n && cmp(arr + right * size, arr + largest * size) > 0) {
            largest = right;
        }

        if (largest != i) {
            swap(arr + largest * size, arr + i * size, size);
            heapify(arr, n, largest, size, cmp);
        }
    }

    void heapSort(void *base, size_t n, size_t size, int (*cmp) (const void *, const void *)) {
        for (int i = (int) n/2 - 1; i >= 0; i--) {
            heapify(base, n, i, size, cmp);
        }

        for (int i = n-1; i > 0;  i--) {
            char *arr = (char *)base;
            swap(arr, arr + i * size, size);
            heapify(base, i, 0, size, cmp);
        }
    }

    int intComp(const void *a, const void *b) {
        return (*((int *)a) - *((int *)b));
    }

    int main() {
        int arr[] = {4, 10, 3, 5, 1};
        int n = sizeof(arr)/sizeof(arr[0]);

        heapSort(arr, n, sizeof(arr[0]), intComp);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);

        return 0;
    }