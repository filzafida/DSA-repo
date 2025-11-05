#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int size;
    int front;
    int rear;
    int *arr;
};

// Function to check if the queue is empty
int isEmpty(struct CircularQueue *q) {
    return (q->front == q->rear);
}

// Function to check if the queue is full
int isFull(struct CircularQueue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

// Function to enqueue (insert)
void Enqueue(struct CircularQueue *q, int val) {
    if (isFull(q)) {
        printf("Queue overflow! Cannot enqueue %d\n", val);
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        printf("Enqueued element: %d\n", val);
    }
}

// Function to dequeue (remove)
int Dequeue(struct CircularQueue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue underflow! Nothing to dequeue.\n");
    } else {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
        printf("Dequeued element: %d\n", a);
    }
    return a;
}

// Function to display queue elements
void Display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = (q->front + 1) % q->size;
    while (i != (q->rear + 1) % q->size) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

// Main function with user menu
int main() {
    struct CircularQueue q;
    int choice, val;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &q.size);

    q.front = q.rear = 0; // initialize to 0 for circular queue logic
    q.arr = (int *)malloc(q.size * sizeof(int));

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                Enqueue(&q, val);
                break;
            case 2:
                Dequeue(&q);
                break;
            case 3:
                Display(&q);
                break;
            case 4:
                if (isEmpty(&q))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 5:
                if (isFull(&q))
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    free(q.arr);
    return 0;
}
