#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int val;
    int originalIdx;
} Item;
 
void merge(Item* arr, int left, int mid, int right, int* result, Item* temp) {
    int i = left;       
    int j = mid + 1;     
    int k = left;        
    int rightCount = 0;  
    
    while (i <= mid && j <= right) {
         
        if (arr[i].val <= arr[j].val) {
            
            result[arr[i].originalIdx] += rightCount;
            temp[k++] = arr[i++];
        } 
     
        else {
            rightCount++; 
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        result[arr[i].originalIdx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

 
void mergeSort(Item* arr, int left, int right, int* result, Item* temp) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, result, temp);
    mergeSort(arr, mid + 1, right, result, temp);
    
    merge(arr, left, mid, right, result, temp);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
 
    int* result = (int*)calloc(numsSize, sizeof(int));
    if (numsSize == 0) return result;

 
    Item* arr = (Item*)malloc(numsSize * sizeof(Item));
    Item* temp = (Item*)malloc(numsSize * sizeof(Item));

   
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].originalIdx = i;
    }

 
    mergeSort(arr, 0, numsSize - 1, result, temp);

     
    free(arr);
    free(temp);

    return result;
}

int main() {
    // Example 1
    int nums1[] = {5, 2, 6, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int returnSize1;
    
    int* result1 = countSmaller(nums1, size1, &returnSize1);
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1); 

    // Example 2
    int nums2[] = {-1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize2;
    
    int* result2 = countSmaller(nums2, size2, &returnSize2);
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    // Example 3
    int nums3[] = {-1, -1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int returnSize3;
    
    int* result3 = countSmaller(nums3, size3, &returnSize3);
    for (int i = 0; i < returnSize3; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");
    free(result3);

    return 0;
}