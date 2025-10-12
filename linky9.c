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
      printf("enter the value for %d node: ",i+1);
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
    return head;
}
void display_linked_list(struct node* ptr){
while(ptr!=NULL){
    printf(" %d\n",ptr->data);
    ptr=ptr->next;
}
}
void freeList(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int compare(struct node* head1,struct node* head2){
    struct node *temp1=head1,*temp2=head2;
    while((temp1->next!=NULL ||temp2->next!=NULL)){
        if(temp1->data!=temp2->data){
            return temp1->data-temp2->data;
        }
            temp1=temp1->next;
            temp2=temp2->next;
        
    }
    if(temp1->next==NULL && temp2->next==NULL && temp1->data==temp2->data){
        return temp1->data-temp2->data;
    }
    else
    return temp1->data!=temp2->data;
}
int main(){
    int n1,n2;
    printf("How many nodes do you want in 1 linked list? ");
    scanf("%d", &n1);
    struct node* head1 = createlist(n1);
    printf("How many nodes do you want in 2 linked list? ");
    scanf("%d", &n2);
    struct node* head2 = createlist(n2);
    printf("the linked lists are\n");
    display_linked_list(head1);
    printf("\n");
    display_linked_list(head2);
     printf("\n");
    int output;
    output=compare(head1,head2);
    if(output>0){
        printf("lists1 is greater");
    }
    else if(output<0){
        printf("list 2 is greater");
    }
    else{
        printf("lists are equal");
    }
     freeList(head1);
     freeList(head2);
    return 0;
}