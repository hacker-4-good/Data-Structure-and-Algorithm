#include <stdio.h>
#include <stdlib.h>
#define max 10
int count = 0;
struct stack
{
    int items[max];
    int top;
};
typedef struct stack st;
void createEmptyStack(st *s)
{
    s->top = -1;
}
int isfull(st *s)
{
    if(s->top == max-1)
        return 1;
    else
        return 0;
}
int isempty(st *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}
void push(st *s,int newitem)
{
    if(isfull(s))
    {
        printf("Stack is full");
        count--;
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
        printf("pushed item: %d",newitem);
    }
    count++;
    printf("\n");
}
void pop(st *s)
{
    if(isempty(s))
    {
        printf("Stack is empty");
        count++;
    }
    else
    {
        printf("Popped item: %d",s->items[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}
void printStack(st *s)
{
    printf("Stack: ");
    for(int i=0;i<count;i++)
    {
        printf("%d ",s->items[i]);
    }
    printf("\n");
}
int main ()
{
    st *s = (st *)malloc(sizeof(st));
    int choice,x;
    createEmptyStack(s);
    printf("Stack Operation: \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the number to be pushed: ");
            scanf("%d",&x);
            push(s,x);
            printStack(s);
            break;

            case 2:
            pop(s);
            printStack(s);
            break;

            case 3:
            exit(0);
            break;

            default:
            printf("Enter the correct choice");
        }
    }
    return 0;
}