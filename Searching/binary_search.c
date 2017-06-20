#include <stdio.h>

int binary_search(int a[],int n,int sch)
{
	int i,j;
	i=0;
	j=n-1;
	while(i<=j)
	{
		int mid=i+(j-i)/2;
		if(a[mid]==sch)
			return mid;
		if(a[mid]<sch)
			i=mid+1;
		else
			j=mid-1;

	}
	return -1;
}

int main()
{
	int arr[]={2,5,9,10,24,27,36};
	int n=sizeof(arr)/sizeof(int);
	printf("%d",binary_search(arr,n,10));
	return 0;
}
