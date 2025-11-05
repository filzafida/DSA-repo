#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *next;
};

// Declare front and rear as global pointers
struct node *front = NULL;
struct node *rear = NULL;

// Function to traverse and print the queue
void LLTraversal(struct node *ptr) {
    if (ptr == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to enqueue (insert) an element
void Enqueue(int val) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    ptr->data = val;
    ptr->next = NULL;

    if (front == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Enqueued: %d\n", val);
}

// Function to dequeue (remove) an element
int Dequeue() {
    int a = -1;
    struct node *ptr = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        front = front->next;
        a = ptr->data;
        free(ptr);
        if (front == NULL) {
            rear = NULL; // queue is now empty
        }
        printf("Dequeued: %d\n", a);
    }
    return a;
}

// Main function with user interaction
int main() {
    int choice, val;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                Enqueue(val);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                LLTraversal(front);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
