#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;
void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete();
void trav();
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
            create();
            break;

            case 2:
            trav();
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
                printf("\nEnter the value you want to insert:");
                scanf("%d",&x);
                insert_begin(x);
                break;

                case 2:
                printf("\nEnter the value you want to insert:");
                scanf("%d",&x);
                printf("\nEnter the value after which you want to insert:");
                scanf("%d",&n);
                insert_middle(n,x);
                break;

                case 3:
                printf("\nEnter the value you want to insert:");
                scanf("%d",&x);
                insert_end(x);
                break;

                case 4:
                break;

                default:
                printf("\nEnter the correct choice");
            }
            break;

            case 4:
            printf("\nEnter the value you want to delete:");
            scanf("%d",&x);
            delete(x);
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("\nEnter the correct choice");
        }
    }
}
void create()
{
    int a,x;
    node *p;
    p = head;
    do
    {
        printf("\nEnter the information part:");
        scanf("%d",&x);
        insert_begin(x);
        printf("\nEnter 0 to exit creation or any thing else to continue\n");
        scanf("%d",&a);
    } while (a!=0);
}
void insert_begin(int x)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    p->next = head;
    head = p;
}
void insert_middle(int n, int x)
{
    node *p,*q;
    p = head;
    q = (node *)malloc(sizeof(node));
    q->info = x;
    while(p->info!=n)
    {
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
}
void insert_end(int x)
{
    node *p,*q;
    q = head;
    p = (node *)malloc(sizeof(node));
    p->info = x;
    p->next = NULL;
    while(q->next!=NULL)
    {
        q = q->next;
    }
    q->next = p;
}
void delete(int x)
{
    node *p,*q;
    q = head;
    if(head==NULL)
        return;
    else if(q->info==x)
    {
        head = head->next;
        free(q);
        return;
    }
    while(q->info!=x)
    {
        p = q;
        q = p->next;
    }
    p->next = q->next;
    free(q);
}
void trav()
{
    node *p;
    p = head;
    printf("\nThe element in the list are:");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p = p->next;
    }
}