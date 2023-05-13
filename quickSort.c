#include <stdio.h>
#include <time.h>

#define DBG 0

void swap(int *a, int *b)
{
    int t = *a;

    *a = *b;

    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        
        quickSort(arr, pi + 1, high);
    }
}

void print(int *v, int n)
{   
    for(int i = 0; i < n; ++ i)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {5141,5721,18631,8331,16113,4755,4170,335,15304,2764,
4355,9214,19490,562,4553,15866,9126,14108,19937,14535,
15073,2457,4329,16767,9901,53,1329,12151,17595,17293,
9003,2736,19366,3986,7420,11832,5094,11590,12167,398,
10707,16523,5964,10197,17085,10518,2416,2563,978,2353
};

    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;

    double totalTime;

    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    totalTime = ((double) (end - start) / CLOCKS_PER_SEC);

    printf("Time needed for %d elements is: %lf\n", n, totalTime);

    #if DBG == 1
    print(arr, n);
    #endif
    return 0;
}
