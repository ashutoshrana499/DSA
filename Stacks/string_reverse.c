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
void print(char * stack , int* top)
{
	for(int i=*top;i>=0;i--)
		printf("%c",stack[i]);
}

int main(int argc, char const *argv[])
{
	char str[] = "passdfsd";
	char stack[100];
	int top = -1;
	for(int i=0;i<strlen(str);i++)
		push(stack,&top,str[i]);
	for(int i=0;i<strlen(str);i++)
		printf("%c",pop(stack,&top));
	return 0;
}