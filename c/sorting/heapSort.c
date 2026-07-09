#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2 - 1; i>=0; i--){
        heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    
    heapSort(arr, size);

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
        printf("%-15.2f\n", time_random);

    }
    return 0;
}