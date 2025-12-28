#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Stack structure
struct Stack {
    struct Node *arr[MAX];
    int top;
};

// Stack operations
void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, struct Node *node) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = node;
}

struct Node* pop(struct Stack *s) {
    if (isEmpty(s))
        return NULL;
    return s->arr[s->top--];
}

// Create new node
struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Postorder traversal without recursion
void postorder(struct Node *root) {
    if (root == NULL)
        return;

    struct Stack s1, s2;
    initStack(&s1);
    initStack(&s2);

    push(&s1, root);

    while (!isEmpty(&s1)) {
        struct Node *curr = pop(&s1);
        push(&s2, curr);

        if (curr->left)
            push(&s1, curr->left);
        if (curr->right)
            push(&s1, curr->right);
    }

    while (!isEmpty(&s2)) {
        printf("%d ", pop(&s2)->data);
    }
}

int main() {
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Postorder traversal: ");
    postorder(root);

    return 0;
}
