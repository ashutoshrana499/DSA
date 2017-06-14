#include <stdio.h>

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
// utility function to swap 2 nos
void swap(int * a,int * b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int l,int r)
{
	int p=a[l];
	int i,j,t;
	i=r+1;
	j=l;
	while(i<=j)
	{
		while(a[j]>=p)
			j++;
		while(a[i]<p && i>0)
			i--;
		swap(&a[i],&a[j]);
	}
	swap(&p,&a[i]);
	return i;
}
/*
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}*/

void quick_sort(int a[],int l,int r)
{
	if(l<r)
	{
		int s=partition(a,l,r);
		quick_sort(a,l,s-1);
		quick_sort(a,s+1,r);
	}
}
int main()
{
	int arr[]={10,3,5,20,24,9};
	int n=sizeof(arr)/sizeof(int);
	quick_sort(arr,0,n-1);
	printArray(arr,n);

	return 0;
}