// C program for implementation of selection sort
#include <stdio.h>
#include <time.h>

#define DBG 0

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int min_idx;

	// One by one move boundary of unsorted subarray
	for (int i = 0; i < n - 1; ++ i)
	{
		min_idx = i;

		for (int j = i + 1; j < n; ++ j)
		{
            if (arr[j] < arr[min_idx])
			{
                min_idx = j;
            }
        }

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; ++ i)
	{
        printf("%d ", arr[i]);
    }
	printf("\n");
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

    selectionSort(arr, n);
    
    end = clock();

    totalTime = ((double) (end - start) / CLOCKS_PER_SEC);

    #if DBG == 1
    printf("Sorted array: \n");
	
    printArray(arr, n);
    #endif

    printf("Time needed for %d elements is: %lf\n", n, totalTime);

    return 0;
}
