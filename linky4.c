//Linked List Reverse

#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int Data;

  struct Node* Link;
};

void display(struct Node* temp);
void revlist(struct Node* temp);

int main()
{
  int i;
  
  //Allocating memory for nodes
  struct Node* Head=(struct Node*)(malloc(sizeof(struct Node)));
  struct Node* First=(struct Node*)(malloc(sizeof(struct Node)));
  struct Node* Second=(struct Node*)(malloc(sizeof(struct Node)));

  Head->Link=First;
  Head->Data=10;
  First->Link=Second;
  First->Data=20;
  Second->Link=NULL;
  Second->Data=30;
  
  display(Head);
  revlist(Head);

  return 0;

}

void display(struct Node* temp)
{
  printf("The Data is: ");
  while(temp!=NULL)
  {
    printf("%d->",(temp->Data));
    temp=temp->Link;
  }
}

void revlist(struct Node* temp)
{

  struct Node *First=temp;
  struct Node *Pres=NULL;
  struct Node *Next=NULL;
  while(temp->Link!=NULL)
  {
    Pres=temp->Link;
    Next=Pres->Link;
    temp->Link=Next;
    Pres->Link=First;
    First=Pres;
  }
  printf("\n Linked List Reversed: \n");
  display(First);
}