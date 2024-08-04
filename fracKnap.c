#include <stdio.h>
#define MAX 50
double p[MAX], w[MAX], x[MAX], maxprofit;
int n, m, i;

void greedyknapsack(int n, double w[], double p[], int m)
{
    double ratio[MAX];
    for (i = 0; i < n; i++)
        ratio[i] = p[i] / w[i];

    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    double currentWeight = 0;
    maxprofit = 0.0;

    for (i = 0; i < n; i++)
    {
        if (currentWeight + w[i] <= m)
        {
            x[i] = 1;
            currentWeight += w[i];
            maxprofit += p[i];
        }
        else
        {
            x[i] = (m - currentWeight) / w[i];
            maxprofit += x[i] * p[i];
            break;
        }
    }

    printf("Optimal solution for greedy method: %lf\n"  , maxprofit);
    printf("Solution vector for greedy method: ");
    for (i = 0; i < n; i++)
        printf("%.2lf\t", x[i]);
}

int main()
{
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the objects' weights: ");
    for (i = 0; i < n; i++)
        scanf("%lf", &w[i]);

    printf("Enter the objects' profits: ");
    for (i = 0; i < n; i++)
        scanf("%lf", &p[i]);

    printf("Enter the capacity: ");
    scanf("%d", &m);

    greedyknapsack(n, w, p, m);

    return 0;
}