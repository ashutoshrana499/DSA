#include <stdio.h>

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
void selection_sort(int a[],int n)
{
	int i,j,min,t;
	min=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
}

int main()
{
	int arr[]={10,3,5,20,24,9};
	int n=sizeof(arr)/sizeof(int);
	selection_sort(arr,n);
	printArray(arr,n);

	return 0;
}