//
// Created by Nicole on 3/7/2016 AD.
//

#include "BubbleSort.h"

bool BubbleSort::isSorted(int *a, int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

void BubbleSort::bubble_sort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void BubbleSort::swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
