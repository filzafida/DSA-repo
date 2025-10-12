#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create_node(int n){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
    
}
struct node* createlist(int size){
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    int value;
    for(int i=0;i<size;i++){
      printf("enter the value for %d node",i+1);
      scanf("%d",&value);
      newnode=create_node(value);
      if(head==NULL){
        head=newnode;
        temp=head;
      }
      else{
        temp->next=newnode;
        temp=newnode;
      }
    }
    temp->next=head;
    return head;
}
void display_linked_list(struct node* head){
    struct node* temp=head;
do{
    printf(" %d\n",temp->data);
    temp=temp->next;
}while(temp!=head);
}
void freeList(struct node* head) {
    struct node* temp=head,* newnode=NULL;
   do{
        newnode=temp->next;
        free(temp);
        temp=newnode;
    }while (temp!= head);
}

int main(){
    int n;
    printf("How many nodes do you want? ");
    scanf("%d", &n);

    struct node* head = createlist(n);
    display_linked_list(head);
    freeList(head);
    return 0;
}