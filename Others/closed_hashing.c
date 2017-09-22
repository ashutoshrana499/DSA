#include <stdio.h>
#include <stdlib.h>
typedef struct map
{
    int key;
    int val;
}map;
int hash_value(int val,int n)
{
    return val%n;
}
int main(int argc, char const *argv[])
{
    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int map[n];
    memset(map,0,sizeof(map));
    for(i=0;i<n;i++)
    {
        int k=arr[i];
        int v = hash_value(arr[i],n);
        if(k<n && map[k]==0)
        {
            map[i]=v;
        }
        else
        {
            for(j=(i+1)%n;j<n;j=(j+1)%n)
            {
                if(map[i]==0)
                    {
                        map[i]=v;
                        break;
                    }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("key %d\t value %d\n",(arr[i]),map[i]);
    }
    int sch;
    scanf("%d",&sch);
    search(arr,map,n,sch);
    return 0;
}
