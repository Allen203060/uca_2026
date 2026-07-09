#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void bubbleSort(int arr[], int n){
    bool swapped;
    for(int i=0; i<n-1; i++){
        swapped = false;    
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
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
     
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    generateFunc(arr, size);

    clock_t start_time = clock();
    
    bubbleSort(arr, size);

    clock_t end_time = clock();

    free(arr);

    return ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;
}


int main(){
    srand(time(NULL));
    int start_size = 368000;
    int step = 4000;
    int iterations = 8;


    for (int i = 0; i < iterations; i++) {
        int current_size = start_size + (i * step);

         
        double time_random = measureExecutionTime(generateRandom, current_size);
        double time_ascending = measureExecutionTime(generateAscending, current_size);
        double time_descending = measureExecutionTime(generateDescending, current_size);

         
        printf("%-10d | %-15.2f | %-15.2f | %-15.2f\n", current_size, time_random, time_ascending, time_descending);
        return 0;
    }
}