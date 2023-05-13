#include <stdio.h>
#include <time.h>
#define MAXSIZE 100001

void counting_sort(int arr[], int n)
{
    int mx = 0;

    int count[MAXSIZE], output[MAXSIZE];

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
        count[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= mx; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {2519, 9793, 5342, 7444, 19372, 8210, 5898, 1190, 15963, 16852};

    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start, end;

    double totalTime;

    start = clock();

    counting_sort(arr, n);

    end = clock();

    totalTime = ((double) (end - start) / CLOCKS_PER_SEC);

    printf("Time needed for %d elements is: %lf\n", n, totalTime);

    return 0;
}
