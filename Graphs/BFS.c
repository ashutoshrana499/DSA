#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  int v;
  scanf("%d",&v);
  int arr[v][v];
  int queue[1000];
  memset(queue,0,sizeof(queue));
  int f=-1,r=-1;

  for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
        scanf("%d",&arr[i][j]);
  r++;
  queue[r]=0;
  int visited[v];
  memset(visited,0,sizeof(visited));

  visited[0]=1;

  while(f<=r)
  {
    f++;
    if(f>r)
      break;
    int x = queue[f];
    printf("%d ",x+1 );
    for(int i=0;i<v;i++)
    {
      if(visited[i]!=1 && arr[x][i]==1)
      {
        queue[++r]=i;
        visited[i]=1;
      }
    }
  }
}
