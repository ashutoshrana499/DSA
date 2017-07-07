#include <stdio.h>

int select_activity(int start[],int end[],int n)
{
	int act=0;
	printf("%d\n",0);
	act++;
	int last = 0;
	for(int i=1;i<n;i++)
	{
		if(start[i]>=end[last])
		{
			printf("%d\n",i);
			last = i;
			act++;
		}
	}
	return act;
}	
int main(int argc, char const *argv[])
{
	//assumed that finish times are sorted
	int start[] = {1,3,0,5,8,5};
	int end[] = {2,4,6,7,9,9};
	int n = sizeof(start)/sizeof(start[0]);
	printf("total %d\n",select_activity(start,end,n));
	return 0;
}