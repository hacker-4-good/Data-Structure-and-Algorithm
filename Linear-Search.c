#include <stdio.h>
int linearSearch(int arr[], int n, int element)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
            return i;
    }
    return -1;
}
int main ()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element = 2;
    int result = linearSearch(arr, n, element);
    (result==-1)?printf("Element is not present in the array"):printf("Element is present in the array at index %d",result);
    return 0;
}
