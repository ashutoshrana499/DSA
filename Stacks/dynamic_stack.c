#include<stdio.h>
void push(int stack[],int ele,int *top,int *size)
{
    if(*top==(*size)-1)
    {
        stack=(int*)realloc(stack,(*size)*2);
        *size=(*size)*2;
        stack[++(*top)]=ele;
    }
    else
        stack[++(*top)]=ele;
}

int pop(int stack[],int *top)
{
    if(*top==-1)
        printf("\n\nunderflow bc");
    else
    return (stack[(*top)--]);
}
void display(int stack[],int top)
{
    int i;
    if(top==-1)
        printf("\n\nempty bc");
    else
        for(i=top;i>=0;i--)
            printf("\n%d",stack[i]);
}
int main()
{
    int top=-1,ch,size,ele,popped;
    int *stack;
    stack=(int *) calloc(5,sizeof(int));
    size=5;
    do{
            printf("\n\n1=push\n2=pop\n3=display\n4=exit");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    scanf("%d",&ele);
                    push(stack,ele,&top,&size);
                    break;
                case 2:
                    popped=pop(stack,&top);
                    printf("\n%d",popped);
                    break;
                case 3:
                    display(stack,top);
                    break;
            }
    }while(ch<=4);
    return 0;
}