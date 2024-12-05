//Program to print the greatest among three numbers. 
/*#include<stdio.h>
int main()
{
    int num1, num2, num3;
    printf("Enter the three numbers:");
    printf("\n1. ");
    scanf("%d", &num1);
    printf("2. ");
    scanf("%d", &num2);
    printf("3. ");
    scanf("%d\n", &num3);
}*/
#include<stdio.h>
int main()
{
    int nums[3],i;
    for(i=0;i<3;i++)
    {
        printf("Enter the %d number: ", i+1);
        scanf("%d", &nums[i]);
    }
    printf("You entered: %d, %d, %d\n", nums[0], nums[1], nums[2]);
    if(nums[0]>nums[1])
        if(nums[0]>nums[2])
            printf("%d is greatest.", nums[0]);
        else
            printf("%d is greatest.", nums[2]);
    else
        if(nums[1]>nums[2])
            printf("%d is greatest.", nums[1]);
        else
            printf("%d is greatest.", nums[2]);
    return 0;
}

