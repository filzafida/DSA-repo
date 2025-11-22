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

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
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
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        printf("\nDuplicate key %d not inserted.", key);
    }

    return root;
}

struct node *Delete_Node(struct node *root, int val)
{
    struct node *iPre;

    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (val < root->data)
    {
        root->left = Delete_Node(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = Delete_Node(root->right, val);
    }
    else
    {

        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = Delete_Node(root->left, iPre->data);
    }
    return root;
}

int main()
{
    int n, val, del;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes.");
        return 0;
    }

    printf("Enter value for root: ");
    scanf("%d", &val);

    struct node *root = create_node(val);

    for (int i = 1; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nInorder Traversal (Before Deletion): ");
    inOrder(root);

    printf("\n\nIs BST: %d\n", isBST(root));

    printf("\nEnter value to delete: ");
    scanf("%d", &del);

    root = Delete_Node(root, del);

    printf("\nInorder Traversal (After Deletion): ");
    inOrder(root);

    printf("\n");

    return 0;
}
