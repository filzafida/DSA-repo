#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *next;
};
void linkedlinktraversal(struct node* ptr){
   while(ptr!=NULL){
       printf("element : %d\n",ptr->data);
       ptr=ptr->next;
   }
}
//case1
struct node *insertatfirst(struct node* head,int data){
struct node * ptr=(struct node *)malloc(sizeof(struct node));
ptr->next=head;
ptr->data=data;
return ptr;}
//case2
struct node *insertatanyindex(struct node*head,int data,int index){
   struct node*ptr=(struct node*)malloc(sizeof(struct node));
   struct node *p=head;
ptr->data=data;

   int i=0;
   while(i!=index-1){
       p=p->next;
       i++;
   }

   ptr->next=p->next;
   p->next=ptr;
   return head;
}
//case3
struct node *insertatend(struct node*head,int data){
   struct node * ptr=(struct node *)malloc(sizeof(struct node));
   struct node *p=head;
   while(p->next!=NULL){
       p=p->next;
   }
   ptr->data=data;
   p->next=ptr;
   ptr->next=NULL;
   return head;
}
//case4
struct node *inserafteranode(struct node* head,struct node* prevnode,int data){
   struct node *ptr=(struct node *)malloc(sizeof(struct node));
   ptr->data=data;
   ptr->next=prevnode->next;

   prevnode->next=ptr;
   return head;

}
int main(){

struct node *head;
struct node *one;
struct node *two;
struct node *three;
head=(struct node *)malloc(sizeof(struct node));
one=(struct node *)malloc(sizeof(struct node));
two=(struct node *)malloc(sizeof(struct node));
three=(struct node *)malloc(sizeof(struct node));

head->data=6;
head->next=one;
one->data=3;
one->next=two;
two->data=8;
two->next=three;
three->data=7;
three->next=NULL;



linkedlinktraversal(head);
// head=insertatfirst(head,4);
// head=insertatanyindex(head,2,1);
// head=insertatend(head,5);
head=inserafteranode(head,two,10);

printf("after insertion: \n");
linkedlinktraversal(head);

return 0;



}