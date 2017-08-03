#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define min(x,y) ((x) <= (y)) ? (x) : (y)
int main(int argc, char const *argv[])
{
    int x, y;
    int op=0;
    scanf("%d%d",&x,&y);
    int gcd = 1;
    int i = min(x,y);
    for(int j=2;j<=i;j++)
    {
        if(x%j==0 && y%j==0)
        {
            op++;
            gcd = j;
        }
    }
    printf("%d\n",gcd);
    printf("op %d\n",op);
    return 0;
}
