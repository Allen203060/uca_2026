#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int population;
    int clinic_count;
} Village;

double getLoad(Village v) {
    return (double) v.population / v.clinic_count;
}

void swap(Village *a, Village *b) {
    Village temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up for insert

void heapifyUp(Village heap[], int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;

        if (getLoad(heap[parent]) < getLoad(heap[idx])) {
            swap(&heap[parent], &heap[idx]);
            idx = parent;
        } else break;
    }
}

// Heapify Down to extract

void heapifyDown(Village heap[], int size, int idx) {

    while (1) {
        int lc = idx * 2 + 1;
        int rc = idx * 2 + 2;
        int largest = idx;
        if (lc < size && getLoad(heap[lc]) > getLoad(heap[largest])) {
            largest = lc;
        }

        if (rc < size && getLoad(heap[rc]) > getLoad(heap[largest])) {
            largest = rc;
        }

        if (largest != idx) {
            swap(&heap[idx], &heap[largest]);
            idx = largest;
        }
        else break;
    } 
}

void push(Village heap[], int *size, Village v) {
    heap[*size] = v;
    heapifyUp(heap, *size);
    (*size)++;
}

Village pop(Village heap[], int *size) {
    Village top = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);

    return top;
}

double minMaxClinic(int population[], int n, int k) {
    Village *heap = (Village *)malloc(sizeof(Village) * k);
    int size = 0;

    for (int i = 0; i < n; i++) {
        Village v = {population[i], 1};
        push(heap, &size, v);
    }

    int clinics = k - n;

    while (clinics-- > 0) {
        Village v = pop(heap, &size);
        v.clinic_count++;
        push(heap, &size, v);
    }

    Village top = pop(heap, &size);
    double result = getLoad(top);

    free(heap);
    return result;
}

int main() {
    int population[] = {200, 20, 50};
    int n = sizeof(population) / sizeof(population[0]);
    int k = 5;

    double result = minMaxClinic(population, n, k);

    printf("Minimum possible maximum load: %.2f\n", result);

    return 0;
}