#include<stdio.h>
#include<stdlib.h>

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

int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root != NULL){
        if(!isBST(root->left))
            return 0;

        if(prev != NULL && root->data <= prev->data)
            return 0;

        prev = root;
        return isBST(root->right);
    }
    return 1;
}

void insert(struct node* root, int key){
    struct node* prev = NULL;

    while(root != NULL){
        prev = root;

        if(root->data == key){
            printf("\nCannot insert %d (Duplicate key)", key);
            return;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    struct node* new = create_node(key);

    if(key < prev->data)
        prev->left = new;
    else
        prev->right = new;

    printf("\nInserted %d successfully.", key);
}

int main(){
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("Invalid number of nodes.");
        return 0;
    }

    printf("Enter value for root: ");
    scanf("%d", &val);

    struct node *root = create_node(val);

   
    for(int i = 1; i < n; i++){
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &val);
        insert(root, val);
    }

  
    printf("\n\nIs BST? : %d", isBST(root));


    printf("\n\nEnter a value to insert: ");
    scanf("%d", &val);
    insert(root, val);

    
    struct node* temp = root;
    while(temp->right != NULL)
        temp = temp->right;

    printf("\nRightmost node : %d\n", temp->data);

    return 0;
}
