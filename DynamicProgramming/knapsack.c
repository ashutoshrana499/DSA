#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int knapsack(int capacity,int wt[],int val[],int n)
{
    if(n==0 || capacity==0)
        return 0;
    if(wt[n-1]>capacity)
        return knapsack(capacity,wt,val,n-1);
    else
        return max(val[n-1] + knapsack(capacity-wt[n-1],wt,val,n-1),knapsack(capacity,wt,val,n-1));
}
 
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int val[n];
    int wt[n];
    int  W;
    for(int i=0;i<n;i++)
        scanf("%d",&val[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&wt[i]);
    scanf("%d",&W);
    printf("%d", knapsack(W, wt, val, n));
    return 0;
}
