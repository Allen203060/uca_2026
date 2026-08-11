#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;

    if (lc < n && arr[lc] > arr[largest]) largest = lc;
    if (rc < n && arr[rc] > arr[largest]) largest = rc;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

void testCase(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    clock_t start, end;
    double cpu_time;

    // Random case
    generateRandom(arr, n);
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Random (%d): %f sec\n", n, cpu_time);

    // Ascending case
    generateAscending(arr, n);
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Ascending (%d): %f sec\n", n, cpu_time);

    // Descending case
    generateDescending(arr, n);
    start = clock();
    heapSort(arr, n);
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Descending (%d): %f sec\n\n", n, cpu_time);

    free(arr);
}

int main() {
    srand(time(0));

    int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};

    for (int i = 0; i < sizeof(sizes)/sizeof(int); i++) {
        testCase(sizes[i]);
    }

    return 0;
}