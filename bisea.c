#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_node(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main() {
    int root_val, left_val, right_val;

    printf("Enter value for root node: ");
    scanf("%d", &root_val);

    printf("Enter value for left child: ");
    scanf("%d", &left_val);

    printf("Enter value for right child: ");
    scanf("%d", &right_val);

    // Create nodes using user input
    struct node *p = create_node(root_val);
    struct node *p1 = create_node(left_val);
    struct node *p2 = create_node(right_val);

    // Link children
    p->left = p1;
    p->right = p2;

    // Display tree
    printf("\nBinary Tree Created:\n");
    printf("      %d\n", p->data);
    printf("     / \\\n");
    printf("    %d   %d\n", p->left->data, p->right->data);

    return 0;
}
