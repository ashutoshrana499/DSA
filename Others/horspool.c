#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char string[300];
    char sub[50];
    gets(string);
    gets(sub);
    int i,j,k,pos=-1;
    int ht[27];
    int str_len=strlen(string);
    int sub_len = strlen(sub);
    memset(ht,0,sizeof(ht));
    for(i=sub_len-2;i>=0;i--)
    {
        if(ht[sub[i]-97]==0)
            ht[sub[i]-97]=sub_len-i-1;
    }
    for(i=0;i<27;i++)
        {
            if(ht[i]!=0)
            printf("%d\n",ht[i]);
        else
            ht[i]=sub_len;
    }
    int count=0;
    for(i=sub_len-1;i<str_len;)
    {
        int k=i;
        if(sub[sub_len-1]==string[i])
        {
            for(j=sub_len-1;j>=0;j--)
            {
                if(sub[j]==string[k])
                {
                    count++;
                    k--;
                }
                else
                {
                    i=i+ht[sub[sub_len-1]];
                    break;
                }
            }
        }
        else
        {
            i=i+ht[string[i]-97];
        }
        if(count==sub_len)
            {
                printf("pattern found\n");
                break;
            }
        else
            count=0;
    }
    return 0;
}