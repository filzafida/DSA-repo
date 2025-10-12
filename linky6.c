#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to merge two sorted lists
struct Node* mergeSorted(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = (head1) ? head1 : head2;
    return dummy.next;
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Example: List 1: 1->3->5
    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);

    // Example: List 2: 2->4->6
    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    // Merge the two sorted lists
    struct Node* merged = mergeSorted(list1, list2);

    printf("Merged Sorted List: ");
    display(merged);

    return 0;
}