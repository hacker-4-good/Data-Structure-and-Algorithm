#include <stdio.h>
int selectionSort(int array[], int size)
{
    for(int step=0;step<size;step++)
    {
        int min_idk = step;
        for(int i=step+1;i<size;i++)
        {
            if(array[i]<array[min_idk])
            {
                min_idk = i;
            }
        }
        int temp = array[step];
        array[step] = array[min_idk];
        array[min_idk] = temp;
    }
}
int printArray(int array[],int size)
{
    for(int j=0;j<size;j++)
    {
        printf("%d ",array[j]);
    }
    printf("\n");
}
int main ()
{
    int array[] = {3,2,1,4,6,5,7,9,8};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    selectionSort(array,size);
    printArray(array,size);
    return 0;
}