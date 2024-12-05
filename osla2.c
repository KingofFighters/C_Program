#include<stdio.h>
#include<limits.h>

// Function to find the process with the shortest remaining time
int findShortestJob(int remainingTime[], int n) {
    int minIndex = -1;
    int minTime = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (remainingTime[i] > 0 && remainingTime[i] < minTime) {
            minTime = remainingTime[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to find the waiting time for each process
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = bt[i];
    }

    int complete = 0, t = 0, minIndex;

    // Continue until all processes are complete
    while (complete != n) {
        minIndex = findShortestJob(remainingTime, n);

        // No process found
        if (minIndex == -1) {
            t++;
            continue;
        }

        // Update waiting time
        wt[minIndex] = t;

        // Decrement remaining time
        remainingTime[minIndex]--;

        // If the process is complete
        if (remainingTime[minIndex] == 0) {
            complete++;
        }

        t++;
    }
}

// Function to find the turnaround time for each process
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to find the waiting time, turnaround time, and average times
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    // Find waiting time for each process
    findWaitingTime(processes, n, bt, wt);

    // Find turnaround time for each process
    findTurnaroundTime(processes, n, bt, wt, tat);

    // Calculate average waiting time and average turnaround time
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
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

    // Display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i]);
    }
    printf("\n");

    // Display the waiting time and turnaround time
    findAverageTime(processes, n, burstTime);

    return 0;
}
