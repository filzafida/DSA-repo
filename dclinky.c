#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Create the list from an array
void create(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            struct Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}

// Insert at position
void insertAtPosition(int data, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* tail = head->prev;

    head = head->next;
    head->prev = tail;
    tail->next = head;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* tail = head->prev;
    struct Node* newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;
    free(tail);
}

// Delete at position
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) return;

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (count < pos && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        printf("Position out of bounds.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Free the entire list
void freeList() {
    if (head == NULL) return;

    struct Node* current = head;
    struct Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);

    head = NULL;
}

// Main function to test
int main() {
    int arr[] = {10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    printf("Initial list: ");
    display();

    insertAtBeginning(5);
    printf("After insertion at beginning: ");
    display();

    insertAtEnd(40);
    printf("After insertion at end: ");
    display();

    insertAtPosition(25, 3);
    printf("After insertion at position 3: ");
    display();

    deleteAtBeginning();
    printf("After deletion at beginning: ");
    display();

    deleteAtEnd();
    printf("After deletion at end: ");
    display();

    deleteAtPosition(2);
    printf("After deletion at position 2: ");
    display();

    freeList(); // Clean up memory
    return 0;
}
