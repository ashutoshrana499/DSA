#include <stdio.h>
#include <stdlib.h>
 
int visited[100];
int push[20];
int pop[20];
int push_i,pop_i;
 
void dfs(int a[][100],int i,int v)
{
    visited[i]=1;
    int j;
    for(j=0;j<v;j++)
    {
        if(j==i)
            continue;
        if(!visited[j] && a[i][j]==1)
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
    int e1,e2,ch;
    pop_i=0;
 
    scanf("%d",&v);
    while(1)
    {
        scanf("%d",&e1);
        scanf("%d",&e2);
        a[e1-1][e2-1]=1;
        a[e2-1][e1-1]=1;
        printf("Enter more?\n");
        scanf("%d",&ch);
        if(ch==0)
            break;
    }

    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            if(a[i][j]!=1)
                a[i][j]=0;

 
    for (int i = 0; i < v; i++)
    {
        visited[i]=0;
    }
 
    for (int i = 0; i < v; i++)
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
    printf("PUSH ORDER : ");
    for (int i = 0; i < push_i; i++)
    {
       
        printf("%d  ",push[i] + 1);
    }
    printf("\n");
 
    printf("POP ORDER : ");
    for (int i = 0; i < pop_i; i++)
    {
       
        printf("%d  ",pop[i] + 1);
    }
    printf("\n");
}
