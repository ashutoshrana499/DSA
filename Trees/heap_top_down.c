#include <stdio.h>
 
void swap(int *p,int *q)
{
    int t=*p;
    *p=*q;
    *q=t;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
    if(l<n)
        heapify(arr,n,l);
     if(r<n)
        heapify(arr,n,r);
}
 
void main ()
{
    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for( i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        heapify(arr,i+1,0);
        printf("\n");
    }
    for(j=0;j<n;j++)
            printf("%d ",arr[j]);
}
