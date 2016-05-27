#include <time.h>
#include <stdlib.h>
#include "BubbleSort.h"

#define N 100000

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int i, n;
    int* A, *temp;
    clock_t start, end;
    double elapsed_time, t1, t2;

    A = (int *)malloc(sizeof(int)*N);
    temp = (int *)malloc(sizeof(int)*N);
    if (A == NULL) {
        printf("Fail to malloc\n");
        exit(1);
    }
    for (i=N-1; i>=0; i--)
        A[N-1-i] = i;

    if (BubbleSort::isSorted(A, N))
        printf("Array is sorted\n");
    else
        printf("Array is NOT sorted\n");

    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    t1 = MPI_Wtime();

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    if (world_rank == 0) {
        MPI_Send(&A, N, MPI_INT, 1, 0, MPI_COMM_WORLD);
        BubbleSort::bubble_sort(A, N/2);
    } else if (world_rank == 1) {
        MPI_Recv(&A, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        BubbleSort::bubble_sort(&A[N/2],N-N/2);
    }

    printArray(&A[N-10], 10);

    if (BubbleSort::isSorted(A, N))
        printf("Array is sorted\n");
    else
        printf("Array is NOT sorted\n");

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d"
                   " out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();
}