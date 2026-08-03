#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right, int pivot_index) {
    int pivot_value = arr[pivot_index];
    
    swap(&arr[pivot_index], &arr[right]);
    int store_index = left;
    
    for (int i = left; i < right; i++) {
        if (arr[i] < pivot_value) {
            swap(&arr[store_index], &arr[i]);
            store_index++;
        }
    }
    
    swap(&arr[store_index], &arr[right]);
    return store_index;
}

void quickselect(int *arr, int left, int right, int k) {
    if (left == right) {
        return;
    }
    
    int pivot_index = left + rand() % (right - left + 1);
    pivot_index = partition(arr, left, right, pivot_index);
    
    if (k == pivot_index) {
        return;
    } else if (k < pivot_index) {
        quickselect(arr, left, pivot_index - 1, k);
    } else {
        quickselect(arr, pivot_index + 1, right, k);
    }
}

void get_smallest_k(int *arr, int n, int k) {
    if (k <= 0 || k > n) return;
    quickselect(arr, 0, n - 1, k - 1);
}

void benchmark_quickselect() {
    int sizes[] = {10000, 50000, 100000, 200000, 500000, 1000000, 2000000, 5000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Dataset Size (n), Time (seconds)\n");
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        
        int *dataset = (int *)malloc(n * sizeof(int));
        if (dataset == NULL) {
            printf("Memory allocation failed for size %d\n", n);
            return;
        }
        
        for (int j = 0; j < n; j++) {
            dataset[j] = rand();
        }
        
        int k = n / 10;
        
        clock_t start_time = clock();
        get_smallest_k(dataset, n, k);
        clock_t end_time = clock();
        
        double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        
        printf("%d, %f\n", n, duration);
        
        free(dataset);
    }
}

int main() {
    srand(time(NULL));
    
 
    benchmark_quickselect();
    
    return 0;
}