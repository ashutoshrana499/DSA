#include <stdio.h>

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

void count_sort(int a[],int n)
{
	//assumed range of numbers is from 0 to 9,hence count array size is 10
	int count[10]={0};
	int i,sum=0;
	int b[n];
	for(i=0;i<n;i++)
		count[a[i]]++;
	for(i=0;i<10;i++)
	{
		sum=sum+count[i];
		count[i]=sum;
	}
	for(i=0;i<n;i++)
	{
		b[--count[a[i]]]=a[i];
	}
	printArray(b,n);
}
int main(int argc, char const *argv[])
{
	int arr[]={1,4,1,2,7,5,2};
	int n=sizeof(arr)/sizeof(int);
	count_sort(arr,n);
	return 0;
}