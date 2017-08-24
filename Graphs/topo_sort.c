#include <stdio.h>
int visited[100];
int push[20];
int pop[20];
int push_i,pop_i;
 
void dfs(int a[][100],int i,int v)
{
    visited[i]=1;
    int j=0;
    for(j=0;j<v;j++)
    {
        if(j!=i && !visited[j] && a[i][j]!=0)
        {
            visited[j]=1;
            push[push_i]=j;
            push_i++;
            dfs(a,j,v);
            pop[pop_i]=j;
            pop_i++;
        }
       
    }
}
 
int main()
{
  int a[100][100];
  int v,i,j;
  push_i=0;
  pop_i=0;
  int e1,e2;
  scanf("%d",&v);
 
  int adj_matrix[v][v];
  int ch;
  while(1)
  {
    scanf("%d",&e1);
    scanf("%d",&e2);
    adj_matrix[e1-1][e2-1]=1;
    adj_matrix[e2-1][e1-1]=1;
    printf("Enter more?\n");
    scanf("%d",&ch);
    if(ch==0)
      break;
  }
 
  for(i=0;i<v;i++)
    for(j=0;j<v;j++)
      if(adj_matrix[i][j]!=1)
        adj_matrix[i][j]=0;
 
  for(i=0;i<v;i++)
    {
      for(j=0;j<v;j++)
        printf("%d ",adj_matrix[i][j]);
      printf("\n");
    }
 
 
  int visited[v];
  memset(visited,0,sizeof(visited));
  for (int i = 0; i < v; ++i)
  {
    if(!visited[i])
    {
      visited[i]=1;
      push[push_i]=i;
      push_i++;
      dfs(a,i,v);
      pop[pop_i]=i;
      pop_i++;
    }
  }
 
  printf("POP ORDER : ");
  for (int i = pop_i-1; i >=0; i--)
    printf("%d  ",pop[i]);
  printf("\n");
 
 
 
}