#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define True 1
#define False 0
int x[10],n,count;

void printsolution()
{
    char c[10][10];
    int i,j;
    printf("Solution %d: \n\n", ++count);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            c[i][j]='X';
        }
    }
    for(i=1; i<=n; i++)
    {
        c[i][x[i]]='Q';
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%c ", c[i][j]);
        }
        printf("\n");
    }
}

int place(int k, int xk)
{
    for(int i=1; i<=k-1; i++)
    {
        if(x[i]==xk || abs(i-k) == abs(x[i]-xk))
        {
            return False;
        }
    }
    return True;
}

void nqueen(int k)
{
    int j;
    for(j=1; j<=n; j++)
    {
        if(place(k,j))
        {
            x[k]=j;
            if(k==n)
                printsolution(), printf("\n");
            else
                nqueen(k+1);
        }
    }
}

void main()
{
    printf("Enter the number of queens\n");
    scanf("%d", &n);
    nqueen(1);
}
