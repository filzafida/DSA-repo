#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // Initialize top pointer

// Function to check if the stack is empty (Underflow)
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }

    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);

    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack
int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();

    display();

    // Empty the stack
    pop();
    pop();

    // Attempt to pop when stack is empty
    pop();  // Underflow

    return 0;
}
