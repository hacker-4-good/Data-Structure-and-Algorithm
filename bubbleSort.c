#include <stdio.h>
int bubbleSort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main ()
{
    int n;
    printf("Enter the number of element in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements in the array: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array: ");
    printArray(arr,n);
    bubbleSort(arr,n);
    printf("Sorted array: ");
    printArray(arr,n);
    return 0;
}