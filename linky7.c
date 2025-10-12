#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



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



void concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}



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


    
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 3);

    append(&list2, 4);
    append(&list2, 5);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    concatenate(list1, list2);

    printf("Concatenated List: ");
    display(list1);

    return 0;
}