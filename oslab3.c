#include<stdio.h>

// Function to calculate average waiting time and average turnaround time
void findAverageTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];

    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = bt[i];
        wt[i] = 0;
        tat[i] = 0;
    }

    int t = 0; // Current time
    int complete = 0; // Number of processes completed

    // Gantt chart
    printf("\nGantt Chart:\n");

    // Continue until all processes are complete
    while (complete != n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                // Execute the process for the quantum or its remaining time, whichever is smaller
                int executeTime = (remainingTime[i] < quantum) ? remainingTime[i] : quantum;

                // Update waiting time only when the process is being executed
                wt[i] += executeTime;

                // Print Gantt chart entry
                printf("| P%d (%d) ", processes[i], executeTime);

                // Update current time
                t += executeTime;

                // Update remaining time
                remainingTime[i] -= executeTime;

                // If the process is complete
                if (remainingTime[i] == 0) {
                    complete++;
                    tat[i] = wt[i] + bt[i];
                }
            }
        }
    }

    printf("|\n");

    // Display the waiting time and turnaround time
    printf("\nWaiting Time for Each Process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: %d\n", processes[i], wt[i]);
    }

    printf("\nTurnaround Time for Each Process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: %d\n", processes[i], tat[i]);
    }

    // Calculate average waiting time and average turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n, quantum;

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

    // Input time quantum
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i]);
    }
    printf("\n");

    // Perform RR scheduling and display Gantt chart
    findAverageTime(processes, n, burstTime, quantum);

    return 0;
}
