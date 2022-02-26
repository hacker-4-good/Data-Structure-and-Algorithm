#include <stdio.h>
int partition(int arr[], int start, int end)
{
    int i,j,pivot,t;
    pivot = arr[end];
    i = start-1;
    for(j=start;j<end;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;
    return i+1;
}
int quickSort(int arr[], int start, int end)
{
    if(start<end)
    {
        int p = partition(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);
    }
}
int printArray(int arr[], int n)
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
    quickSort(arr,0,n-1);
    printf("Sorted array: ");
    printArray(arr,n);
    return 0;
}