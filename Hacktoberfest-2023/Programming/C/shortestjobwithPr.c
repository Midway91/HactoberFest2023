#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[]) {
    int rt[n];
    
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }
    
    int complete = 0, t = 0, minm = INT_MAX, shortest = 0, finish_time;
    int check = 0;
    
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((rt[j] <= t) && (rt[j] < minm) && (rt[j] > 0)) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }
        
        if (check == 0) {
            t++;
            continue;
        }
        
        rt[shortest]--;
        
        minm = rt[shortest];
        
        if (minm == 0) {
            minm = INT_MAX;
        }
        
        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
            
            wt[shortest] = finish_time - bt[shortest];
            
            if (wt[shortest] < 0) {
                wt[shortest] = 0;
            }
        }
        
        t++;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    findWaitingTime(n, bt, wt);
    findTurnAroundTime(n, bt, wt, tat);
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    
    float avg_wt = (float) total_wt / n;
    float avg_tat = (float) total_tat / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int burst_time[n];
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    
    findAverageTime(n, burst_time);
    
    return 0;
}
