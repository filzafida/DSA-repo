

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;

    struct Node *Link;
};

struct Node *Head;

void create();
void display();

int main()
{
    create();

    return 0;
}

void create()
{
    int i, n;

    do
    {
        printf("Enter the number of Nodes: ");
        scanf("%d", &n);

        if (n < 2)
        {
            printf("ERROR\n");
        }
    } while (n < 2);

    struct Node *Temp_1 = NULL;
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            Head = (struct Node *)(malloc(sizeof(struct Node)));

            printf("Enter Data for Node %d: ", i);
            scanf("%d", &Head->Data);

            Temp_1 = Head;
        }
        else
        {
            struct Node *Temp_2 = (struct Node *)(malloc(sizeof(struct Node)));

            printf("Enter Data for Node %d : ", i);
            scanf("%d", &Temp_2->Data);

            Temp_2->Link = NULL;

            Temp_1->Link = Temp_2;
            Temp_1 = Temp_2;
        }
    }

    display();
}

void display()
{
    struct Node *Temp = Head;

    printf("The data is: ");
    while (Temp != NULL)
    {
        printf("%d ", Temp->Data);

        Temp = Temp->Link;
    }
}