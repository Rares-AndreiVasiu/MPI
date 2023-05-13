#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100001
#define DBG 0

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;

    int n1 = m - l + 1;

    int n2 = r - m;

    // Create temp arrays
    int L[MAXSIZE], R[MAXSIZE];

    for (i = 0; i < n1; ++i)
    {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; ++j)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;

    j = 0;

    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];

            i++;
        }
        else
        {
            arr[k] = R[j];

            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);

        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {5141, 5721, 18631, 8331, 16113, 4755, 4170, 335, 15304, 2764,
                 4355, 9214, 19490, 562, 4553, 15866, 9126, 14108, 19937, 14535,
                 15073, 2457, 4329, 16767, 9901, 53, 1329, 12151, 17595, 17293,
                 9003, 2736, 19366, 3986, 7420, 11832, 5094, 11590, 12167, 398,
                 10707, 16523, 5964, 10197, 17085, 10518, 2416, 2563, 978, 2353};

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    #if DBG == 1
    printf("Given array is \n");
    printArray(arr, arr_size);

    #endif

    clock_t start, end;

    double totalTime;

    start = clock();

    mergeSort(arr, 0, arr_size - 1);

    end = clock();

    totalTime = ((double) (end - start) / CLOCKS_PER_SEC);

    printf("Time needed for %d elements is: %lf\n", arr_size, totalTime);

    #if DBG == 1
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    #endif

    return 0;
}
