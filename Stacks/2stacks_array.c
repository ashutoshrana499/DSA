#include<stdio.h>
#define max 10
void push(int stack[],int ele,int *top1,int *top2,int no)
{
    if(*top1==(*top2)-1)
        printf("\n\noverflow");
    else
    {
        if(no==1)
            {
            stack[++(*top1)]=ele;
            }
        else
        {
            stack[--(*top2)]=ele;
        }

    }
}

int pop(int stack[],int *top,int no)
{
    if(no==1)
    {
        if(*top==-1)
            printf("\n\nunderflow");
        else
            return stack[(*top)--];
    }
    else
    {

        if(*top==max)
            printf("\n\nunderflow");
        else
            return stack[(*top)++];
    }
}

void disp(int stack[],int top,int no)
{
    int i;
    if(no==1)
    {
        if(top==-1)
            printf("\n\nempty");
        else
            for(i=top;i>=0;i--)
                printf("%d\n",stack[i]);
    }
    else
    {
        if(top==max)
             printf("\n\nempty");
        else
            for(i=top;i<=max-1;i++)
                printf("%d\n",stack[i]);
    }
}

int main()
{
   int stack[max],top1=-1,top2=max,ch,no,ele,deleted;
    do{
            printf("\n\n1=push\n2=pop\n3=display\n4=exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    scanf("%d%d",&ele,&no);
                    if(no==1)
                        push(stack,ele,&top1,&top2,no);
                    else
                        push(stack,ele,&top1,&top2,no);
                    break;
                case 2:
                    scanf("%d",&no);
                    if(no==1)
                       deleted=pop(stack,&top1,no);
                    else
                       deleted=pop(stack,&top2,no);
                    printf("\n%d",deleted);
                    break;
                case 3:
                        scanf("%d",&no);
                        if(no==1)
                            disp(stack,top1,no);
                    else
                            disp(stack,top2,no);
                    break;
            }
    }while(ch<4);
    return 0;
}

