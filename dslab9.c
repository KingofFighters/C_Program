#include <stdio.h>
#include <stdlib.h>

// Define structure for a queue node.
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data.
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty.
int isEmpty(struct Node* front) {
    return (front == NULL);
}

// Function to enqueue (insert an element at the rear of the queue).
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;  // If queue is empty, front and rear will point to the new node
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue (remove an element from the front of the queue).
int dequeue(struct Node** front, struct Node** rear) {
    if (isEmpty(*front)) {
        printf("Queue underflow\n");
        return -1;  // Return a sentinel value to indicate error
    }
    struct Node* temp = *front;
    int dequeuedData = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;  // If the queue becomes empty, set rear to NULL
    }
    free(temp);
    printf("%d dequeued from queue\n", dequeuedData);
    return dequeuedData;
}

// Function to peek (view the front element without removing it).
int peek(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return -1;  // Return a sentinel value to indicate error
    }
    return front->data;
}

// Function to print all elements in the queue.
void printQueue(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the queue.
void freeQueue(struct Node* front) {
    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
    printf("Queue memory freed\n");
}

int main() {
    struct Node* front = NULL;  // Start with an empty queue
    struct Node* rear = NULL;   // Start with an empty queue

    // Enqueue some elements
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    
    // Print the queue
    printQueue(front);
    
    // Peek at the front element
    printf("Front element is %d\n", peek(front));

    // Dequeue an element
    dequeue(&front, &rear);
    
    // Print the queue after dequeue
    printQueue(front);
    
    // Dequeue another element
    dequeue(&front, &rear);
    
    // Print the queue after dequeue
    printQueue(front);
    
    // Dequeue the last element
    dequeue(&front, &rear);
    
    // Try to dequeue from an empty queue
    dequeue(&front, &rear);
    
    // Free the queue memory
    freeQueue(front);
    
    return 0;
}
