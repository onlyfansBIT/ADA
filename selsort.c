#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;

    for (i = 0; i <= n - 2; i++)
    {
        min_idx = i;
        for (j = i + 1; j <= n - 1; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main()
{
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(NULL));

    printf("Original Array: ");
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    clock_t start, end;

    start = clock();
    selectionSort(arr, n);
    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTime Complexity: O(n^2)");
    printf("\nTime taken: %f\n", time_taken);

    return 0;
}