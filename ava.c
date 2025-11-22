#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* right;
    struct node* left;
    int height;
};

int height(struct node* n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

struct node* createNode(int key){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->key = key;
    p->right = NULL;
    p->left = NULL;
    p->height = 1;
    return p;
}

void preOrder(struct node* root){
    if(root != NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int get_BalanceFactor(struct node* n){
    if(n == NULL){
        return 0;
    }
    return height(n->left) - height(n->right);
}

struct node* right_rotate(struct node* y){
    struct node* x = y->left;
    struct node* T2 = x->right;

    // rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* left_rotate(struct node* x){
    struct node* y = x->right;
    struct node* T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

struct node* insert(struct node* n, int key){
    if(n == NULL){
        return createNode(key);
    }

    if(key < n->key){
        n->left = insert(n->left, key);
    }
    else if(key > n->key){
        n->right = insert(n->right, key);
    }
    else{
        return n;  // duplicate keys not allowed
    }

    n->height = 1 + max(height(n->left), height(n->right));

    int BF = get_BalanceFactor(n);

    // Left Left Case
    if(BF > 1 && key < n->left->key){
        return right_rotate(n);
    }

    // Right Right Case
    if(BF < -1 && key > n->right->key){
        return left_rotate(n);
    }

    // Left Right Case
    if(BF > 1 && key > n->left->key){
        n->left = left_rotate(n->left);
        return right_rotate(n);
    }

    // Right Left Case
    if(BF < -1 && key < n->right->key){
        n->right = right_rotate(n->right);
        return left_rotate(n);
    }

    return n;
}

int main(){
    struct node* root = NULL;
    int n, key;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("\nPreOrder Traversal of AVL Tree:\n");
    preOrder(root);

    return 0;
}
