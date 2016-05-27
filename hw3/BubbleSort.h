//
// Created by Nicole on 3/7/2016 AD.
//
#include <mpi.h>

#ifndef WEB_APPLICATION_DEV_BUBBLESORT_H
#define WEB_APPLICATION_DEV_BUBBLESORT_H


class BubbleSort {
public:
    static void bubble_sort(int arr[], int n);
    static bool isSorted(int *a, int size);

private:
    static void swap(int *xp, int *yp);
};


#endif //WEB_APPLICATION_DEV_BUBBLESORT_H
