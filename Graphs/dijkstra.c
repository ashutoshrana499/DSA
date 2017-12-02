#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define v 9
int min(int sptSet[],int dist[],int n)
{
	int m = 999;
	int pos = -1;
	for(int i=0;i<n;i++)
		if(sptSet[i]==0 && dist[i]<m)
			{
				m=dist[i];
				pos = i;
			}
	return pos;
}
int main()
{
	//int v;
	int i,j;
	//scanf("%d",&v);
	/*int adj_matrix[v][v];
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&adj_matrix[i][j]);*/
	int adj_matrix[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
	int sptSet[v];
	memset(sptSet,0,sizeof(sptSet));
	int dist[v];
	for(i=1;i<v;i++)
		dist[i]=999;
	dist[0]=0;
	j=0;
	for(int count=0;count<v;count++)
	{
		int vert = min(sptSet,dist,v);
		sptSet[vert]=1;
			sptSet[vert]=1;
			for(i=0;i<v;i++)
			{
				if(adj_matrix[vert][i] && sptSet[i]==0 && dist[vert]!=999)
				{
					if((dist[vert] + adj_matrix[vert][i])<dist[i])
					{
						dist[i]=dist[vert]+adj_matrix[vert][i];
					}
				}
			}
	}
	for(i=0;i<v;i++)
		printf("%d\t%d\n",i,dist[i]);
}