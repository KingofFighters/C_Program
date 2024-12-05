// Passing array as an argument to a function
#include<stdio.h>
int avg(int[],int);
int main()
{
    int marks[5]= {10,20,30,40,50},size,average;
    size = sizeof(marks)/sizeof(marks[0]);
    average = avg(marks,size);
    printf("average =  %d\n",average);
    printf("inside main size of array(in bytes)is: %lu\n",sizeof(marks));
}
int avg(int marks1[], int size)
{
    int i, sum, average;
    for(i=0;i<size;i++)
    {
        sum = sum + marks1[i];
    }
    average = sum/size;
    printf("inside avg size of array(in bytes)is: %lu\n",sizeof(marks1));
    return average;
}