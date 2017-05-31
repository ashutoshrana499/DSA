#include <stdio.h>

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
int kadane(int arr[],int n)
{
	int max_so_far,max_end_here;
	max_end_here=max_so_far=0;
	for (int i = 0; i < n; i++)
	{
		max_end_here=max_end_here+arr[i];
		if(max_end_here<0)
			max_end_here=0;
		if(max_so_far<max_end_here)
			max_so_far=max_end_here;
	}
	return max_so_far;
	
}

int main()
{
	int arr[]={-2,-3,4,-1,-2,1,5,-3};
	int n=sizeof(arr)/sizeof(int);
	int max=kadane(arr,n);
	printArray(arr,n);
	printf("%d\n",max);

	return 0;
}