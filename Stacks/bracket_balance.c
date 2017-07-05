#include <stdio.h>
#include <string.h>

void push(char *  stack , int * top,char ele)
{
	stack[++(*top)]=ele;
}

char pop(char *  stack , int * top)
{
	return stack[(*top)--];
}
int main(int argc, char const *argv[])
{
	int q;
	scanf("%d",&q);
	for(int count = 0;count<q;count++)
	{
		char  stack[500];
		char b[1000];
		int top = -1;
		scanf("%s",b);
		for(int i=0;i<strlen(b);i++)
		{
			if(b[i]=='{'||b[i]=='['||b[i]=='(')
				{
					push(stack,&top,b[i]);
					//printf("%d\n",top);
				}		
			else if((b[i]=='}' && stack[top]=='{')||(b[i]==']' && stack[top]=='[')||(b[i]==')' && stack[top] == '('))
			{
				char t = pop(stack,&top);
				//printf("%dcvcv\n",top);
			}
		}
		//printf("%d\n",top );
		if(top != -1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}