#include<stdio.h>
void findWaitingTime(int processes[], int n,int bt[],int wt[])
{
    wt[0]= 0;
    for(int i=0;i<n;i++)
    {
        wt[i]= wt[i-1]+bt[i-1];
    }
}
void findTurnaroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]= bt[i]+wt[i];
    }
}
void findAverageTime(int processes,int n, int bt[]){
    int wt[n], tat[n]
    findWaitingTime(processes, n, wt, bt);
    findTurnaroundTime(processes, n, wt, bt, tat);
    // Calculate average waiting time and average turnaround time
    float total_wt=0, total_tat=0;
    for(int i=0;i<n;i++)
    {
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}
// Function to perform SJF scheduling
void sjfScheduling(int processes[], int n, int bt[]) {
    // Sort the processes based on burst time using selection sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                // Swap process IDs
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i]);
    }
    printf("\n");

    // Display the waiting time and turnaround time
    findAverageTime(processes, n, bt);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burstTime[n];

    // Input burst time for each process
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        processes[i] = i + 1; // Process IDs start from 1
    }

    // Perform SJF scheduling
    sjfScheduling(processes, n, burstTime);

    return 0;
}
