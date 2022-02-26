#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head = NULL;
void insert(node **head,int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next     = NULL;
    if(*head == NULL)
         *head = newNode;
    else
    {
        node *lastNode = *head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

}
int power(int base,int exp)
{
    long int result = 1;
    while(exp!=0)
    {
        result *= base;
        --exp;
    }
    return result;
}
void traverse()
{
    node *p;
    p = head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
void palindrome()
{
    int key,num=0,q,count=0,rev=0,last;
    node *p;
    p = head;
    while(p!=NULL)
    {
        key = p->data;
        q = power(10,count);
        num = num + key*q;
        count++;
        p = p->next;
    }
    int ori_num = num;
    while(num!=0)
    {
        last = num%10;
        rev = rev*10 + last;
        num /= 10;
    }
    if(rev==ori_num)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
}
int main ()
{
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    traverse();
    printf("\n");
    palindrome();
    return 0;
}