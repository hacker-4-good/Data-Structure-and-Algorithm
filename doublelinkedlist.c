#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev,*next;
};
struct node *start = NULL;
void traverse()
{
    if(start==NULL)
    {
        printf("\nList is empty");
        return;
    }
    struct node *temp;
    temp = start;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp = temp->next;
    }
}
void insertAtFront()
{
    int data;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the number to be inserted: ");
    scanf("%d",&data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = start;
    start = temp;
}
void insertAtEnd()
{
    int data;
    struct node *temp,*trav;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter the number to be inserted: ");
    scanf("%d",&data);
    temp->info = data;
    temp->next = NULL;
    trav = start;
    if(start==NULL)
    {
        start = temp;
    }
    else
    {
        while(trav->next!=NULL)
        {
            trav = trav->next;
        }
        temp->prev = trav;
        trav->next = temp;
    }
}
void insertAtPosition()
{
    int data,pos,i=1;
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(start==NULL)
    {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else if(pos==1)
    {
        insertAtFront();
    }
    else
    {
        printf("\nEnter the number to be inserted: ");
        scanf("%d",&data);
        newnode->info = data;
        temp = start;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}
void deleteFirst()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp = start;
        start = start->next;
        if(start!=NULL)
            start->prev = NULL;
        free(temp);
    }
}
void deleteEnd()
{
    struct node *temp;
    if(start==NULL)
    {
        printf("\nList is empty");
    }
    temp = start;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    if(start->next==NULL)
        start = NULL;
    else
    {
        temp->prev->next = NULL;
        free(temp);
    }
}
void deletePosition()
{
    int pos,i=1;
    struct node *temp, *position;
    temp = start;
    if(start==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nEnter the position: ");
        scanf("%d",&pos);
        if(pos==1)
        {
            deleteFirst();
        }
        if(start!=NULL)
        {
            start->prev = NULL;
        }
        free(position);
        return;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
            position = temp->next;
        if(position->next!=NULL)
        {
            position->next->prev = temp;
        }
        temp->next = position->next;
        free(position);
    }
}
void main ()
{
    int i,j,ch,x,n;
    while(1)
    {
        printf("\n Enter");
        printf("\n1. Creation");
        printf("\n2. Traversing");
        printf("\n3. Insertion");
        printf("\n4. Deletion");
        printf("\n5. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insertAtFront();
            break;

            case 2:
            printf("Data: ");
            traverse();
            break;

            case 3:
            printf("\nEnter");
            printf("\n1. Insert at begin");
            printf("\n2. Insert at middle");
            printf("\n3. Insert at the end");
            printf("\n4. Exit");
            printf("\nMention your choice:");
            scanf("%d",&i);
            switch(i)
            {
                case 1:
                insertAtFront(x);
                break;

                case 2:
                insertAtPosition();
                break;

                case 3:
                insertAtEnd();
                break;

                case 4:
                break;

                default:
                printf("\nEnter the correct choice");
            }
            break;

            case 4:
            printf("\nEnter");
            printf("\n1. Delete at begin");
            printf("\n2. Delete at middle");
            printf("\n3. Delete at the end");
            printf("\n4. Exit");
            printf("\nMention your choice:");
            scanf("%d",&i);
            switch(i)
            {
                case 1:
                deleteFirst();
                break;

                case 2:
                deletePosition();
                break;

                case 3:
                deleteEnd();
                break;

                case 4:
                break;

                default:
                printf("\nEnter the correct choice");
            }
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("\nEnter the correct choice");
        }
    }
}