#include <stdio.h>
#define max 5
int stack[max];
int top = -1;
int count = 0;
int isfull()
{
    if(top==max-1)
        return 1;
    return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    return 0;
}
void push(int value)
{
    if(isfull())
    {
        printf("Stack is full");
    }
    else
    {
        top = top+1;
        stack[top] = value;
        printf("Pushed item: %d",value);
        count++;
    }
    printf("\n");
}
void pop()
{
    if(isempty())
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Popped item: %d",stack[top]);
        top = top-1;
        count--;
    }
    printf("\n");
}
void printStack()
{
    printf("Stack: ");
    for(int i=0;i<count;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main ()
{
    int ch,val;
    printf("Enter the choice: ");
    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\n4. Exit");
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the data: ");
            scanf("%d",&val);
            push(val);
            break;

            case 2:
            pop();
            break;

            case 3:
            printStack();
            break;

            case 4:
            break;

            default:
            printf("Enter the choice: ");
        }
    } while (ch!=4);
    return 0;
}