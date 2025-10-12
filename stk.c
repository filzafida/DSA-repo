#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum stack size

int stack[MAX];
int top = -1;

// Check if the stack is full (overflow)
int isFull() {
    return top == MAX - 1;
}

// Check if the stack is empty (underflow)
int isEmpty() {
    return top == -1;
}

// Push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        int poppedValue = stack[top];
        top--;
        printf("%d popped from the stack.\n", poppedValue);
        return poppedValue;
    }
}

// Display the current stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function to test the stack
int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // Attempt to push when full
    push(60);  // Should show overflow

    display();

    pop();
    pop();

    display();

    // Emptying the stack completely
    pop();
    pop();
    pop();

    // Attempt to pop when empty
    pop();  // Should show underflow

    return 0;
}
