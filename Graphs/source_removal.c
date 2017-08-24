#include <stdio.h>
int main()
{
  int v;
  scanf("%d",&v);
  int adj[v][v];
  int i,j;
  for(i=0;i<v;i++)
    for(j=0;j<v;j++)
      scanf("%d",&adj[i][j]);
  int in[v];
  int c=0;
  memset(in,0,sizeof(in));
  int ci=0;
  for(i=0;i<v;i++)
  {
    c=0;
    for(j=0;j<v;j++)
    {
      c+=adj[j][i];
    }
    in[i]=c;
  }
 
  int vert_count=0;
  while(vert_count<v)
  {
    for(i=0;i<v;i++)
    {
      if(in[i]==0)
      {
        printf("%d ",i+1);
        in[i]=-1;
        for(j=0;j<v;j++)
        {
          if(adj[i][j]==1)
          {
            adj[i][j]--;
            in[j]--;
          }
        }
      }
    }
    vert_count++;
  }
 
}