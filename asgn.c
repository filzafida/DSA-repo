#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Enqueue
void enqueue(Queue *q, int x) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = x;
}

// Dequeue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

// Stack using two queues
Queue q1, q2;

// Push operation
void push(int x) {
    enqueue(&q2, x);

    while (!isEmpty(&q1))
        enqueue(&q2, dequeue(&q1));

    // Swap q1 and q2
    Queue temp = q1;
    q1 = q2;
    q2 = temp;
}

// Pop operation
int pop() {
    if (isEmpty(&q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return dequeue(&q1);
}

// Display stack
void display() {
    if (isEmpty(&q1)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = q1.front; i <= q1.rear; i++)
        printf("%d ", q1.arr[i]);
    printf("\n");
}


int main() {
    initQueue(&q1);
    initQueue(&q2);

    push(10);
    push(20);
    push(30);

    printf("Stack elements: ");
    display();

    printf("Popped: %d\n", pop());
    printf("Stack elements: ");
    display();

    return 0;
}
