#include <stdio.h>
int merge(int array[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1],M[n2];
    for(int i=0;i<n1;i++)
        L[i] = array[p + i];
    for(int j=0;j<n2;j++)
        M[j] = array[q + 1 + j];
    int i,j,k;
    i = 0;
    j = 0;
    k = p;
    while(i<n1 && j<n2)
    {
        if(L[i]<=M[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = M[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        array[k] = M[j];
        j++;
        k++;
    }
}
int mergeSort(int array[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergeSort(array,l,m);
        mergeSort(array,m+1,r);
        merge(array,l,m,r);
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
    int array[] = {9,1,8,2,7,3,6,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    mergeSort(array,0,size-1);
    printArray(array,size);
    return 0;
}