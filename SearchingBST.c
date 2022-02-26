#include <stdio.h>
#include <stdlib.h>
#define max 10
int top;
int stack[max];
struct tree
{
    int info;
    struct tree *rt;
    struct tree *lf;
};
typedef struct tree node;
node *root = NULL;
node *n = NULL;
int insert();
int search();
void main ()
{
    int i,ch,x,n,a,x1;
    while(1)
    {
        printf("\nEnter the choice");
        printf("\n1. Creation");
        printf("\n2. Search");
        printf("\n3. exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the number of nodes you want: ");
            scanf("%d",&a);
            printf("\nEnter %d element: \n",a);
            for(int i=0;i<a;i++)
            {
                scanf("%d",&x);
                insert(x);
            }
            break;

            case 2:
            printf("\nEnter the element you want to search: ");
            scanf("%d",&x);
            x1 = search(x);
            printf("\nLocation: %d",x1);
            break;

            case 3:
            exit(0);
            break;

            default:
            printf("Enter the correct choice");
        }
    }
}
int insert(int x)
{
    node *ptr,*par,*p;
    ptr = (node *)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("can't insert");
    }
    else
    {
        ptr->info = x;
        ptr->lf = NULL;
        ptr->rt = NULL;
        if(root==NULL)
        {
            root = ptr;
            root->lf = NULL;
            root->rt = NULL;
        }
        else
        {
            par = NULL;
            p = root;
            while(p!=NULL)
            {
                par = p;
                if(x<p->info)
                {
                    p = p->lf;
                }
                else
                {
                    p = p->rt;
                }
            }
            if(x<par->info)
            {
                par->lf = ptr;
            }
            else
            {
                par->rt = ptr;
            }
        }
        printf("Node inserted");
    }
}
int search(int x)
{
    int level;
    node *p;
    p = root;
    level = 0;
    if(root==NULL)
    {
        printf("\nLevel does not exists");
        return NULL;
    }
    if(root->info==x)
    {
        printf("Level: %d",level);
        return root;
    }
    else
    {
        if(root->info>x)
            p = root->lf;
        else
            p = root->rt;
            level = 1;
        while(p!=NULL)
        {
            if(p->info==x)
            {
                printf("\nLevel: %d",level);
                return p;
            }
            else
            {
                if(p->info>x)
                    p = p->lf;
                else
                    p = p->rt;
                level++;
            }
        }
    }
    if(root->info!=x)
    {
        printf("\nSearch Unsucccessful");
        return NULL;
    }
}