//FCFS
#include<stdio.h>
void findWaitingTime(int processes[],int n,int bt[],int wt[])
{
    wt[0]= 0;
    for(int i=1;i<n;i++)
        wt[i]= wt[i-1]+bt[i-1];
}
void findTurnaroundTime(int processes[],int n,int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]= bt[i]+wt[i];
    }
}
void findAverageTime(int processes[],int n,int bt[])
{
    int wt[n],tat[n];
    findWaitingTime(processes,n,bt,wt);
    findTurnaroundTime(processes,n,bt,wt,tat);
    float total_wt=0,total_tat=0;
    for(int i=0;i<n;i++)
    {
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    printf("Average Waiting Time:%0.2f\n",total_wt/n);
    printf("Average Turnaround Time:%0.2f\n",total_tat/n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int processes[n];
    int burstTime[n];
    printf("Enter burst time for each process: \n");
    for(int i=0;i<n;i++)
    {
        printf("Burst time for process %d: ",i+1);
        scanf("%d",&burstTime[i]);
        processes[i]= i+1;
    }
    printf("Order of execution: ");
    for(int i=0;i<n;i++)
    {
        printf("%d", processes[i]);
    }
    printf("\n");
    findAverageTime(processes,n,burstTime);
    return 0;
}