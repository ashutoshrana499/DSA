#include <stdio.h>

int linear_search(int a[],int n,int sch)
{
	int i;
	int pos=-1;
	for(i=0;i<n;i++)
		if(a[i]==sch)
		{
			pos=i;
			return pos;
		}
	return pos;
}

int main()
{
	int arr[]={10,3,5,20,24,9};
	int n=sizeof(arr)/sizeof(int);
	printf("%d",linear_search(arr,n,5));
	return 0;
}