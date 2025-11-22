#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return create_node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;

    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;

        if (prev != NULL && root->data <= prev->data)
            return 0;

        prev = root;
        return isBST(root->right);
    }
    return 1;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

struct node *search_by_iteration(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main()
{
    struct node *root = NULL;
    int n, val, key;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nPreOrder Traversal: ");
    preOrder(root);

    printf("\nPostOrder Traversal: ");
    postOrder(root);

    printf("\ninOrder Traversal: ");
    inOrder(root);

    if (isBST(root))
    {
        printf("\n\nThe tree is a BST\n");
    }
    else
    {
        printf("\n\nThe tree is not a BST\n");
    }

    printf("\nEnter value to search (recursive): ");
    scanf("%d", &key);
    struct node *found1 = search(root, key);

    if (found1 != NULL)
        printf("Found: %d\n", found1->data);
    else
        printf("Not found.\n");

    printf("\nEnter value to search (iterative): ");
    scanf("%d", &key);
    struct node *found2 = search_by_iteration(root, key);

    if (found2 != NULL)
        printf("Found: %d\n", found2->data);
    else
        printf("Not found.\n");

    return 0;
}
