#include <stdio.h>
int binarySearch(int arr[], int element, int low, int high)
{
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==element)
            return mid;
        else if(arr[mid]<element)
            low = mid + 1;
        else if(arr[mid]>element)
            high = mid - 1;
    }
    return -1;
}
int main ()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element = 2;
    int result = binarySearch(arr, element, 0, n);
    (result==-1)?printf("Element is not present in the array"):printf("Element is present in the array at index %d",result);
    return 0;
}
