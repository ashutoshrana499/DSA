#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getMin(int mstSet[],int key[],int v)
{
	int min = 999,pos;
	for (int i = 0; i < v; ++i)
			if(mstSet[i]==0 && key[i]<min)
				{
					min = key[i];
					pos=i;
				}
	return pos;
}
int printMST(int parent[], int n, int graph[][100])
{
   printf("Edge   Weight\n");
   for (int i = 0; i < n-1; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
int main(int argc, char const *argv[])
{
	int i,j;
	int v;
	int adj_mat[v][v];
	scanf("%d",&v);
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&adj_mat[i][j]);
	int mstSet[v];
	memset(mstSet,0,sizeof(mstSet));
	int key[v];
	for(i=0;i<v;i++)
		key[i]=999;
	key[0]=0;
	int tree[v];
	tree[0]=-1;
	for(i=0;i<v;i++)
	{
		int cur = getMin(mstSet,key,v);
		mstSet[cur]=1;
		printf("%d\n",cur);
		for(j=0;j<v;j++)
		{
			if(adj_mat[cur][j] && mstSet[j]==0)
			{
				if(adj_mat[cur][j]<key[j])
					{
						key[j]=adj_mat[cur][j];
						tree[j]=cur;
					}
			}
		}
	}
	printf("dfsdf\n");
	for(i=0;i<v-1;i++)
		printf("%d\n",tree[i]);
}
/*
5
0 2 0 6 0 
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/