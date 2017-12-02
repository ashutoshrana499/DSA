#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct edge
{
	int src;
	int dest;
}edge;
//get root of element i
int arr[10];
int root(int arr[ ],int i)
{
    while(arr[ i ] != i)           
     i = arr[ i ];
    return i;
}
//combines 2 disconnected components
int union2(int arr[ ] ,int a ,int b)
{
    int root_A = root(arr, a);       
    int root_B = root(arr, b);  
    arr[root_A] = root_B;   //set parent of root(A) as root(B)
}
//find whether an edge from a to b exists
int find(int a,int b)
{
	if(root(arr,a)==root(arr,b))
		return 1;
	else
		return 0;
}
void checkCycle(edge edges[],int e,int visited[])
{
	for(int i=0;i<e;i++)
	{
		if(visited[i]==0)
		{
			if(find(edges[i].src,edges[i].dest))
			{
				printf("cycle detected\n");
				return;
			}
			else
				union2(arr,edges[i].src,edges[i].dest);
		}
	}
	printf("no cycle\n");
}
int main(int argc, char const *argv[])
{
	int i,j;
	int v,e;
	scanf("%d%d",&v,&e);
	edge edges[e];
	for(i=0;i<e;i++)
		scanf("%d%d",&edges[i].src,&edges[i].dest);
	int visited[e];
	memset(visited,0,sizeof(visited));
	//array to store parent of current node
	//init
	for(i=0;i<v;i++)
		arr[i]=i;
	checkCycle(edges,e,visited);
	return 0;
}