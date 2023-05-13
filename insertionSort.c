#include <math.h>
#include <stdio.h>
#include <time.h>

#define DBG 0

void insertionSort(int *arr, int n)
{
    int key, j;

    for (int i = 1; i < n; ++ i)
    {
        key = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];

            j --;
        }
        arr[j + 1] = key;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; ++ i)
    {
        printf("%d ", arr[i]);
    }

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

    int n = sizeof(arr) / sizeof(arr[0]);
    
    clock_t start, end;

    double totalTime;

    start = clock();

    insertionSort(arr, n);

    end = clock();

    totalTime = ((double) (end - start) / CLOCKS_PER_SEC);

    #if DBG == 1
        printArray(arr, n);
    #endif

    printf("Time needed for %d elements is: %lf\n", n, totalTime);
    return 0;
}
