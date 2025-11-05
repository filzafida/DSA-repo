#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q) {
    return (q->rear == q->size - 1);
}

int isEmpty(struct queue *q) {
    return (q->rear == q->front);
}

void Enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        q->rear++;
        q->arr[q->rear] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int Dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main() {
    struct queue q;
    int choice, val;

    printf("Enter the size of the queue: ");
    scanf("%d", &q.size);

    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                Enqueue(&q, val);
                break;
            case 2:
                val = Dequeue(&q);
                if (val != -1)
                    printf("Dequeued element: %d\n", val);
                break;
            case 3:
                if (isEmpty(&q))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 4:
                if (isFull(&q))
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    free(q.arr);
    return 0;
}
