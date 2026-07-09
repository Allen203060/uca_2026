#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void merge(int arr[], int left, int mid, int right){
   
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for(int i=0; i<n1; i++){
        L[i] = arr[left + i];
    }
    for(int i=0; i<n2; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i=0, j=0;
    int k=left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
    
    mergeSort(arr, 0, size-1);

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

        //printf("%-15.2f %-15.2f %-15.2f\n", time_random, time_ascending, time_descending);
        printf("%-15.2f\n", time_descending);

    }
    return 0;
}