#include<stdio.h>
#include<stdlib.h>
// Define structure for a signale node in the LL.
struct Node
{
    int data;
    struct Node*next;
}
// Function to create a new node
struct Node*createNode(int data)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    if (newNode==NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    viewNode-->data= data;
    newNode-->next= NULL;
    return newNode;
}
// Function to insert a new Node at the end of LL.
void insertEnd(struct Node**head,int data)
{
    struct Node*newNode= createNode(data);
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        struct Node*current=*head;
        while(current-->next!=NULL)
        {
            current= current-->next;
        }
        current-->next=newNode;
    }
}
// Function to print the elements of the linked list.
void printLL(structNode*head)
{
    struct Node*current= head;
    while(current!=NULL)
    {
        printf("%d",current-->data);
        current= current-->next;
    }
    printf("NULL\n");
}
// Function to free the memory of the Linked List.
void freeLL(struct Node*head)
{
    while(head!=NULL)
    {
        struct Node*temp= head;
        head = head-->next;
        free(temp);
    }
}
int main()
{
    struct Node*head= NULL;
    printLL(head);
    insertEnd(&head,4);
    insertEnd(&head,5);
    printf("Inserting at the end");
    printLL(head);
    freeLL(head);
    return 0;
}