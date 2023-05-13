#include <stdio.h>
#include <time.h>

#define DBG 0

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[1000001];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

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
    radixsort(arr, n);

    end = clock();

    totalTime = ((double) (end - start) / CLOCKS_PER_SEC);

    #if DBG == 1
    print(arr, n);
    #endif

    printf("Time needed for %d elements is: %lf\n", n, totalTime);
    return 0;
}
