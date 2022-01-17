#include <stdio.h>
int insertionSort(int array[], int size)
{
    for(int step=1;step<size;step++)
    {
        int key = array[step];
        int j = step-1;
        while(key<array[j]&&j>=0)
        {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
}
int printArray(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main ()
{
    int array[] = {3,6,9,8,7,4,5,2,1};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    insertionSort(array,size);
    printArray(array,size);
    return 0;
}