#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int priority[]) {
    int rem_bt[n];
    
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }
    
    int complete = 0, t = 0, highest_priority = 0;
    int check = 0;
    
    while (complete != n) {
        highest_priority = -1;
        
        for (int i = 0; i < n; i++) {
            if (bt[i] > 0 && priority[i] > highest_priority) {
                highest_priority = priority[i];
                check = 1;
            }
        }
        
        if (check == 0) {
            t++;
            continue;
        }
        
        int process = -1;
        
        for (int i = 0; i < n; i++) {
            if (bt[i] > 0 && priority[i] == highest_priority) {
                if (process == -1 || bt[i] < bt[process]) {
                    process = i;
                }
            }
        }
        
        rem_bt[process]--;
        
        if (rem_bt[process] == 0) {
            complete++;
            check = 0;
            wt[process] = t + 1 - bt[process];
        }
        
        t++;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int n, int bt[], int priority[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    findWaitingTime(n, bt, wt, priority);
    findTurnAroundTime(n, bt, wt, tat);
    
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], priority[i], wt[i], tat[i]);
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
    
    int burst_time[n], priority[n];
    printf("Enter the burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    
    findAverageTime(n, burst_time, priority);
    
    return 0;
}
