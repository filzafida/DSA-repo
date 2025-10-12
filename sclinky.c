#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create list from array
void create(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            struct Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
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
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
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
    struct Node* last = head;
    while (last->next != head)
        last = last->next;
    head = head->next;
    last->next = head;
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
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

// Delete at position
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) return;
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    int count = 1;
    while (count < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count != pos) {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Free the entire list
void freeList() {
    if (head == NULL) return;
    struct Node* temp = head;
    struct Node* nextNode;
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
    head = NULL;
}

// Main function
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

    freeList(); // Cleanup

    return 0;
}
