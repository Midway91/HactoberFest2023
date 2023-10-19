#include <stdio.h>

int main()
{
    int i, j, n;
    printf("Enter the number of processes:");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("\nEnter the burst time of each processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    // calculating waiting time
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // calculating turn around time
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] = bt[i];
    }

    float avgwt = 0, avgtat = 0;

    // calculating average waiting time and average turn around time
    for (int i = 0; i < n; i++)
    {
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("\nThe average waiting time is : %2.f", avgwt);
    printf("\nThe average turn around time is : %2.f", avgtat);

    return 0;
}