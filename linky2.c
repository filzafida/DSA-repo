#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next;
};
void linkedlinktraversal(struct node *ptr){
   while(ptr!=NULL){
       printf("elements are: %d\n",ptr->data);
       ptr=ptr->next;
   }
}
//case1 delete the first
struct node* deletethefirst(struct node *head){

   struct node *ptr=head;
   head=head->next;
   free(ptr);
   return head;

}
//case2 delete in between
struct node *deleteinbetween(struct node *head,int index){
   struct node *p=head;
   struct node *q=head->next;
   for(int i=0;i<index-1;i++){
       p=p->next;
       q=q->next;

   }
           p->next=q->next;
           free(q);
           return head;
       }


//case3:delete at end
struct node *deleteatend(struct node *head){
   struct node *p=head;
   struct node *q=p->next;
   while(q->next!=NULL){
       p=p->next;
       q=q->next;}
p->next=NULL;
free(q);
return head;
       }
   //case4 delete at agiven value
   struct node *deleteatvalue(struct node *head,int value){
       struct node *p=head;
       struct node *q=p->next;
       while(q->data!=value && q!=NULL){
           p=p->next;
           q=q->next;
       }
       if(q->data==value){
           p->next=q->next;
           free(q);
           return head;
       }

    }

int main() {
   struct node*head;
   struct node*one;
   struct node*two;
   struct node*three;
   head=(struct node *)malloc(sizeof(struct node));
   one=(struct node *)malloc(sizeof(struct node));
   two=(struct node *)malloc(sizeof(struct node));
   three=(struct node *)malloc(sizeof(struct node));
   head->data=1;
   head->next=one;
    one->data=6;
   one->next=two;
    two->data=8;
   two->next=three;
    three->data=4;
   three->next=NULL;
   linkedlinktraversal(head);
   printf("after deletion \n");
   // head=deletethefirst(head);
   head=deleteinbetween(head,3);
   // head=deleteatend(head);
   // head=deleteatvalue(head,8);

   linkedlinktraversal(head);

   return 0;


}



