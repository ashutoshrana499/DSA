#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char const *argv[])
{
    int n,i,j,k;
    scanf("%d",&n);
    int adj[n+1][n+1];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&adj[i][j]);
    int r[n+1][n+1];
    memset(r,0,sizeof(r));
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                adj[i][j]=adj[i][j]||(adj[i][k]&&adj[k][j]);
            }
        }
    }
    printf("\n");
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%d ",adj[i][j]);
            printf("\n");
        }
    return 0;
}
