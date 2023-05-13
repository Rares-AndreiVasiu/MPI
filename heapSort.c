#include <stdio.h>
#include <time.h>

#define DBG 0

void swap(int *a, int *b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; --i)

        heapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++ i)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Driver's code
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

    heapSort(arr, n);

    end = clock();

    totalTime = ((double) (end - start) / CLOCKS_PER_SEC);

    printf("Sorted array is\n");
    
    printArray(arr, n);
}
