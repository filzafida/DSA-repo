//Linked List Functions//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    
    struct Node *Link;
};

struct Node *Head;
int size;

void create();
void read();
void display(int flag);
void search();
void insertion();
void deletion();
void freespace();


int main()
{
    create();
    read();
    display(0);
    search();
    insertion();
    deletion();
    freespace();
    
    return 0;
}

void create()
{
  int i;

  do
  {
    printf("Enter the number of Nodes: ");
    scanf("%d",&size);

    if(size<2)
    {
      printf("ERROR\n");
    }
  } while (size<2);

  struct Node *Temp_1=NULL;
  for(i=1;i<=size;i++)
  {
    if(i==1)
    {
      Head=(struct Node*)(malloc(sizeof(struct Node)));
      
      Temp_1=Head;
    }
    else
    {
      struct Node *Temp_2=(struct Node*)(malloc(sizeof(struct Node)));
      Temp_2->Link=NULL;

      Temp_1->Link=Temp_2;
      Temp_1=Temp_2;
    }
  }
}

void read()
{
    int n=1;
    struct Node* temp=Head;
    while(temp!=NULL)
    {
    printf("Enter Data for Node %d: ",n);
    scanf("%d",&(temp->Data));
    temp=temp->Link;
    n++;
    }
}

void display(int flag)
{
    struct Node *temp=Head;
    if(flag==0)
    {
      printf("The Data is:\n");
    }
    else
    {
      printf("The new Data is:\n");
    }

    while(temp!=NULL)
    {
    printf("%d ",temp->Data);
    temp=temp->Link;
    }
    printf("\n");
}

void search()
{
  int x,n=1,flag=0;
  struct Node *temp=Head;

  printf("Enter the Data you want to search for: ");
  scanf("%d",&x);

  while(temp!=NULL)
  {
    if(temp->Data==x)
    {
      printf("The data was found in Node %d: ",n);
      flag=1;
    }
    temp=temp->Link;
    n++;
  }
  if(flag==0)
  {
    printf("The Data was not found.\n");
  }
}

void insertion()
{
   int n;

   do
   {
    printf("\nEnter the position where to add Node\nEnter 0 for Exit\n");
    scanf("%d",&n);

    if(n==1)
    {
      struct Node *temp=malloc(sizeof(struct Node));
      printf("Enter the Data for new Node\n");
      scanf("%d",&temp->Data);

      temp->Link=Head;
      Head=temp;
      size++;

      display(1);
    }
    else if(n>1&&n<=(size+1))
    {
      int i=1;
      struct Node *temp_1=Head;
      struct Node *temp_2;

      struct Node *temp=malloc(sizeof(struct Node));
      printf("Enter the Data for new Node: \n");
      scanf("%d",&temp->Data);

      while(i<(n-1))
      {
        temp_1=temp_1->Link;
        i++;
      }

      temp_2=temp_1->Link;

      temp_1->Link=temp;
      temp->Link=temp_2;
      
      size++;

      display(1);
    
    }
    else
    {
      break;
    }
    
   } while (n!=0);
   
}

void deletion()
{
  int n;

  do
  {
    printf("\nEnter the position of Node to delete\nEnter 0 for exit\n");
    scanf("%d",&n);

    if(n==1)
    {
      Head=Head->Link;

      display(1);
    }
    else if(n>1&&n<=size)
    {
      int i=1;

      struct Node *temp=Head;

      while(i<(n-1))
      {
        temp=temp->Link;
        i++;
      }

      temp->Link=temp->Link->Link;

      display(1);

    }
    else
    {
      break;
    }
  } while (n!=0);
  

}

void freespace()
{
  struct Node* temp=Head;
  struct Node* tempn=NULL;
  while(temp!=NULL)
  {
    tempn=temp->Link;
    free(temp);
    temp=tempn;
  }
}