//pre-emptive
#include <stdio.h>
#include <limits.h>

// Structure to represent a process
struct Process {
    int id;
    int burstTime;
    int priority;
    int arrivalTime;
    int remainingTime;
    int startTime;  // Start time of the process
};

// Function to find the process with the highest priority
int findHighestPriority(struct Process processes[], int n, int currentTime) {
    int highestPriority = INT_MAX;
    int processIndex = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime <= currentTime && processes[i].priority < highestPriority && processes[i].remainingTime > 0) {
            highestPriority = processes[i].priority;
            processIndex = i;
        }
    }

    return processIndex;
}

// Function to calculate average waiting time and average turnaround time
void findAverageTime(struct Process processes[], int n) {
    int wt[n], tat[n];

    // Initialize remaining time and start time
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].startTime = -1; // Indicates process has not started yet
    }

    int t = 0; // Current time
    int complete = 0; // Number of processes completed

    // Continue until all processes are complete
    while (complete != n) {
        int highestPriorityIndex = findHighestPriority(processes, n, t);

        // If no process is ready to execute
        if (highestPriorityIndex == -1) {
            t++;
            continue;
        }

        // If the process is starting for the first time, update its start time
        if (processes[highestPriorityIndex].startTime == -1) {
            processes[highestPriorityIndex].startTime = t;
        }

        // Execute the process for 1 unit
        processes[highestPriorityIndex].remainingTime--;

        // If the process is complete
        if (processes[highestPriorityIndex].remainingTime == 0) {
            complete++;
            tat[highestPriorityIndex] = t + 1 - processes[highestPriorityIndex].arrivalTime;
        }

        t++;
    }

    // Calculate waiting time for each process
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - processes[i].burstTime;
    }

    // Display the waiting time and turnaround time
    printf("\nWaiting Time for Each Process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: %d\n", processes[i].id, wt[i]);
    }

    printf("\nTurnaround Time for Each Process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: %d\n", processes[i].id, tat[i]);
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
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input details for each process
    printf("Enter details for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        processes[i].id = i + 1; // Process IDs start from 1
        printf("Burst time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrivalTime);
    }

    // Display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", processes[i].id);
    }
    printf("\n");

    // Perform Priority scheduling and display results
    findAverageTime(processes, n);

    return 0;
}
