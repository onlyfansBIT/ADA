#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[], int low, int high)
{
    int pivot=a[low];
    int i=low,temp;
    int j=high+1;

    while(i<=j){
        do i++; while(pivot >= a[i]);
        do j--; while(pivot < a[j]);

        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

        temp=a[low];
        a[low]=a[j];
        a[j]=temp;

        return j;
}

void quicksort(int a[], int low, int high)
{
    if(low>high) return;

    int k=partition(a,low,high);
    quicksort(a,low,k-1);
    quicksort(a,k+1,high);
}

int main()
{
    srand(time(0));
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("Randomly generated array:\n");
    for(int i=0; i<n; i++){
        a[i]=rand()%1000;
        printf("%d ", a[i]);
    }
    a[n]=9999;

    clock_t start = clock();
    quicksort(a,0,n-1);
    clock_t stop = clock();

    printf("\nSorted array:\n");
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Total time taken to sort %d elements is %lf\n", n, (double)(stop-start)/CLOCKS_PER_SEC);

    return 0;
}

