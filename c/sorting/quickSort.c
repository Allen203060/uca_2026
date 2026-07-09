#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int arr[], int left, int right){
    int mid = left + (right - left)/2;
    swap(&arr[mid], &arr[right]);
    int pivot = arr[right];
    int i = (left - 1);
    for(int j=left; j<right; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return i+1;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);

        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}

void generateRandom(int arr[], int n){
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100000;
    }
}

void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i; 
    }
}

void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i; 
    }
}

double measureExecutionTime(void (*generateFunc)(int[], int), int size) {

    if (size <= 0) {
        return 0.0;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    generateFunc(arr, size);

    clock_t start_time = clock();
    
    quickSort(arr, 0, size-1);

    clock_t end_time = clock();

    free(arr);

    return ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;
}


int main(){
    srand(time(NULL));

    int sizes[] = {0, 8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);   


    for (int i = 0; i < num_sizes; i++) {
        int current_size = sizes[i];

        double time_random = measureExecutionTime(generateRandom, current_size);
        double time_ascending = measureExecutionTime(generateAscending, current_size);
        double time_descending = measureExecutionTime(generateDescending, current_size);

        // printf("%-15.2f %-15.2f %-15.2f\n", time_random, time_ascending, time_descending);
        printf("%-15.2f\n", time_descending);

    }
    return 0;
}