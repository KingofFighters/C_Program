#include<stdio.h>
#include<stdlib.h>
//Define the structure for a stack node.
struct Node{
    int data;
    struct Node*next;
};
//Function to create a new node with given data.
struct Node*createNode(int data){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
if(!newNode){
    printf("Memory allocation error\n");
    exit(EXIT_FAILURE);
}
newNode->data=data;
newNode->next=NULL;
return newNode;
}
//Function to check if the stack is empty.
int isEmpty(struct Node*top){
    return(top==NULL);
}
//Function to push a new element onto the stack.
void push(struct Node**top,int data){
    struct Node* newNode= createNode(data);
    new Node->next=*top;
    *top=newNode;
    printf("%d ")
}