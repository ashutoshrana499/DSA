#include<stdio.h>
#include<string.h>
#define siz 500
int tabs[siz];
void shifttable(char p[])
{
 int i,j,m;
 m=strlen(p);
 for(i=0;i<siz;i++)
  tabs[i]=m;
 for(j=0;j<m-1;j++)
  tabs[p[j]]=m-1-j;
}
int horspool(char t[],char p[])
{
 int i,j,k,m,n;
 n=strlen(t);
 m=strlen(p);
 i=m-1;
 while(i<n)
 {
  k=0;
  while((k<m)&&(p[m-1-k]==t[i-k]))
   k++;
  if(k==m)
   return(i-m+1);
  else
   i+=tabs[t[i]];
 }
 return -1;
}
void main()
{
 char t[100],p[100];
 int pos;
 printf("Enter the text\n");
 gets(t);
 printf("Enter the pattern\n");
 gets(p);
 shifttable(p);
 pos=horspool(t,p);
 if(pos>=0)
  printf("pattern found starting from position %d\n",pos+1);
 else
  printf("The pattern was not found\n");
}
