#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct edge
{
	int src;
	int dest;
	int weight;
}edge;
//get root of element i
int arr[10];
int v;
void init()
{
	for(int i=0;i<v;i++)
		arr[i]=i;
}
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
int checkCycle(edge edges[],int e)
{
	init();
	for(int i=0;i<e;i++)
	{
			if(find(edges[i].src,edges[i].dest))
			{
				return 1;
			}
			else
				union2(arr,edges[i].src,edges[i].dest);
	}
	return 0;
}
void sort(edge edges[],int e)
{
	edge E;
	int i,j;
	for(i=0;i<e-1;i++)
		for(j=0;j<e-1-i;j++)
		{
			if(edges[j].weight>edges[j+1].weight)
			{
				E=edges[j];
				edges[j]=edges[j+1];
				edges[j+1]=E;
			}
		}
}
int main(int argc, char const *argv[])
{
	int i,j;
	int e,ne=0;
	scanf("%d%d",&v,&e);
	edge edges[e];
	edge tree[v-1];
	for(i=0;i<e;i++)
		scanf("%d%d%d",&edges[i].src,&edges[i].dest,&edges[i].weight);
	//array to store parent of current node
	//init
	sort(edges,e);
	i=0,j=0;
	while(ne<v)
	{
		edge E = edges[i];
		tree[j] = E;
		int res = checkCycle(tree,ne+1);
		if(res == 1)
		{
			i++;
		}
		else
		{
			j++;
			i++;
			ne++;
			if(ne==v-1)
				break;
		}
	}
	printf("%d\n",ne);
	for(i=0;i<ne;i++)
		printf("%d\t%d\t%d\n",tree[i].src,tree[i].dest,tree[i].weight);
	return 0;
}
/*
4
5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/