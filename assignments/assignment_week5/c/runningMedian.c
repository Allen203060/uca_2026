#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

//maxHeap
typedef struct {
    int *arr;
    int size;
    int capacity;
} MaxHeap;

void initMaxHeap(MaxHeap *h) {
    h->size = 0;
    h->capacity = INITIAL_CAPACITY;
    h->arr = (int *)malloc(sizeof(int) * h->capacity);
}

void resizeMaxHeap(MaxHeap *h) {
    h->capacity *= 2;
    h->arr = (int *)realloc(h->arr, sizeof(int) * h->capacity);
}

void maxHeapInsert(MaxHeap* h, int val) {
    if (h->size == h->capacity) resizeMaxHeap(h);

    int i = h->size++;
    while (i > 0 && h->arr[(i - 1) / 2] < val) {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = val;
}

int maxHeapExtract(MaxHeap *h) {
    int root = h->arr[0];
    int last = h->arr[--h->size];

    int i = 0;
    while (2 * i + 1 < h->size) {
        int child = 2 * i + 1;
        if (child + 1 < h->size && h->arr[child + 1] > h->arr[child])
            child++;

        if (last >= h->arr[child]) break;

        h->arr[i] = h->arr[child];
        i = child;
    }
    h->arr[i] = last;
    return root;
}

int maxHeapTop(MaxHeap *h) {
    return h->arr[0];
}

//minHeap
typedef struct {
    int *arr;
    int size;
    int capacity;
} MinHeap;

void initMinHeap(MinHeap *h) {
    h->size = 0;
    h->capacity = INITIAL_CAPACITY;
    h->arr = (int *)malloc(sizeof(int) * h->capacity);
}

void resizeMinHeap(MinHeap *h) {
    h->capacity *= 2;
    h->arr = (int *)realloc(h->arr, sizeof(int) * h->capacity);
}

void minHeapInsert(MinHeap *h, int val) {
    if (h->size == h->capacity)
        resizeMinHeap(h);

    int i = h->size++;
    while (i > 0 && h->arr[(i - 1) / 2] > val) {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = val;
}

int minHeapExtract(MinHeap *h) {
    int root = h->arr[0];
    int last = h->arr[--h->size];

    int i = 0;
    while (2 * i + 1 < h->size) {
        int child = 2 * i + 1;
        if (child + 1 < h->size && h->arr[child + 1] < h->arr[child])
            child++;

        if (last <= h->arr[child]) break;

        h->arr[i] = h->arr[child];
        i = child;
    }
    h->arr[i] = last;
    return root;
}

int minHeapTop(MinHeap *h) {
    return h->arr[0];
}

typedef struct {
    MaxHeap leftMax;
    MinHeap rightMin;
} MedianFinder;

void initMedianFinder(MedianFinder *mf) {
    initMaxHeap(&mf->leftMax);
    initMinHeap(&mf->rightMin);
}

void addNum(MedianFinder *mf, int num) {
    maxHeapInsert(&mf->leftMax, num);
    minHeapInsert(&mf->rightMin, maxHeapExtract(&mf->leftMax));

    if (mf->rightMin.size > mf->leftMax.size) {
        maxHeapInsert(&mf->leftMax, minHeapExtract(&mf->rightMin));
    }
}

double findMedian(MedianFinder *mf) {
    if (mf->leftMax.size == mf->rightMin.size) {
        return (maxHeapTop(&mf->leftMax) + minHeapTop(&mf->rightMin)) / 2.0;
    }
    return maxHeapTop(&mf->leftMax);
}

 
void freeMedianFinder(MedianFinder *mf) {
    free(mf->leftMax.arr);
    free(mf->rightMin.arr);
}

 
int main() {
    MedianFinder mf;
    initMedianFinder(&mf);

    addNum(&mf, 10);
    // addNum(&mf, 20);
    addNum(&mf, 30);
    addNum(&mf, -10);
    printf("Median: %.2f\n", findMedian(&mf));  

    addNum(&mf, 5);
    printf("Median: %.2f\n", findMedian(&mf)); 

    freeMedianFinder(&mf);
    return 0;
}   