#include <stdio.h>

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

int main()
{
	int arr[]={10,3,5,20,24,9};
	int n=sizeof(arr)/sizeof(int);
	int i,j;
	for(i=1;i<n;i++)
	{
		int key=arr[i];
		for(j=i-1; j >= 0 && arr[j]>key;j--)
			arr[j+1]=arr[j];
		arr[j+1]=key;
	}
	printArray(arr,n);

	return 0;
}