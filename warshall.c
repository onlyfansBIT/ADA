#include<stdio.h>

void warsh(int p[][10], int n)
{
    int i,j,k;

    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                p[i][j]=p[i][j]||p[i][k]&&p[k][j];
}

int main()
{
    int a[10][10],n,i,j;

    printf("Enter the n value: ");
    scanf("%d", &n);

    printf("Enter the graph data: ");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);0

    warsh(a,n);
    
    printf("\nResultant path matrix:\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}