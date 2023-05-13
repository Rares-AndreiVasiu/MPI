#include <stdio.h>
#include <time.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];

    arr[i] = arr[j];

    arr[j] = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}

// Driver code
int main()
{
    int arr[] = {5141, 5721, 18631, 8331, 16113, 4755, 4170, 335, 15304, 2764,
                 4355, 9214, 19490, 562, 4553, 15866, 9126, 14108, 19937, 14535,
                 15073, 2457, 4329, 16767, 9901, 53, 1329, 12151, 17595, 17293,
                 9003, 2736, 19366, 3986, 7420, 11832, 5094, 11590, 12167, 398,
                 10707, 16523, 5964, 10197, 17085, 10518, 2416, 2563, 978, 2353};

    int N = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;

    double totalTime;

    start = clock();

    bubbleSort(arr, N);

    end = clock();

    totalTime = ((double)(end - start) / CLOCKS_PER_SEC);

    printf("Timed need to sort %d elements: %lf\n", N, totalTime);

    return 0;
}
