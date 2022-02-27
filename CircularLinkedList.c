#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;
void create(int value)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->data = value;
    p->next = p;
    head = p;
}
void insert_begin(int value)
{
    node *p,*q;
    q = head;
    p = (node *)malloc(sizeof(node));
    p->data = value;
    p->next = head;
    while(q->next!=head)
    {
        q = q->next;
    }
    q->next = p;
    head = p;
}
void insert_end(int value)
{
    node *p,*q;
    q = head;
    p = (node *)malloc(sizeof(node));
    p->data = value;
    p->next = head;
    while(q->next!=head)
    {
        q = q->next;
    }
    q->next = p;
}
void insert_middle(int term, int value)
{
    node *p,*q;
    q = head;
    p = (node *)malloc(sizeof(node));
    p->data = value;
    while(q->data!=term)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}
void print()
{
    printf("Circular Linked List: ");
    node *p;
    p = head;
    if(head!=NULL)
    {
        do
        {
            printf("%d ",p->data);
            p = p->next;
        } while (p!=head);
    }
    printf("\n");
}
int main ()
{
    int ch,choi,x,n;
    do
    {
        printf("Enter the choice to perform operation on Circular Linked List:");
        printf("\n1. Create");
        printf("\n2. Insert");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the data for first time: ");
            scanf("%d",&x);
            create(x);
            break;

            case 2:
            printf("\n1. Insert at beginning");
            printf("\n2. Insert at middle");
            printf("\n3. Insert at end");
            printf("\nEnter the choice: ");
            scanf("%d",&choi);
            switch(choi)
            {
                case 1:
                printf("Enter the data part: ");
                scanf("%d",&x);
                insert_begin(x);
                break;

                case 2:
                printf("Enter the data after which you want to insert: ");
                scanf("%d",&n);
                printf("Enter the data part: ");
                scanf("%d",&x);
                insert_middle(n,x);
                break;

                case 3:
                printf("Enter the data part: ");
                scanf("%d",&x);
                insert_end(x);
                break;

                default:
                printf("Enter the correct choice");
            }
            break;

            case 3:
            print();
            break;

            case 4:
            break;

            default:
            printf("Enter the correct choice");
        }
    }while(ch!=4);
    return 0;
}