#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void mergesort(int[], int, int);
void merge(int[], int, int, int);

int main() 
{
    int a[MAX];
    int i, n;
    clock_t start, stop;
    double duration;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Populate the array with random numbers
    for(i = 0; i < n; i++)
        a[i] = rand() % 1000;

    // Start timing the sort
    start = clock();
    mergesort(a, 0, n - 1);
    // Stop timing the sort
    stop = clock();

    // Calculate the duration in seconds
    duration = (double)(stop - start) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("The sorted array is:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    // Print the duration
    printf("The time taken is %lf seconds\n", duration);

    return 0;
}

void mergesort(int a[], int low, int high) 
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int low, int mid, int high) 
{
    int b[MAX];
    int h, i, j, k;
    h = i = low;
    j = mid + 1;

    while ((h <= mid) && (j <= high)) {
        if (a[h] <= a[j])
            b[i++] = a[h++];
        else
            b[i++] = a[j++];
    }

    if (h > mid)
        for (k = j; k <= high; k++)
            b[i++] = a[k];
    else
        for (k = h; k <= mid; k++)
            b[i++] = a[k];

    for (k = low; k <= high; k++)
        a[k] = b[k];
}
