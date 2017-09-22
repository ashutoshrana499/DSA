#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main(int argc, char const *argv[])
{
    int size;
    printf("enter the size\n");
    scanf("%d",&size);
    struct node *arr[size];
    for(int i=0;i<=size-1;i+=1)
        arr[i]=NULL;
    int no;
    while(1)
    {
        printf("enter the number\n");
        scanf("%d",&no);
        int index=no%size;
        if(arr[index]==NULL)
        {
            struct node *p=(struct node*)malloc(sizeof(struct node));
            p->data=no;
            p->next=NULL;
            arr[index]=p;
        }
        else
        {
            struct node *p=arr[index];
            while(p->next!=NULL)
            {
                p=p->next;
            }
            struct node *temp=(struct node*)malloc(sizeof(struct node));
            temp->data=no;
            temp->next=NULL;
            p->next=temp;
        }
        printf("do you want to continue?\n");
        scanf("%d",&no)
        if(no==0)
            break;
    }
    for(int i=0;i<=size-1;i+=1)
    {
        struct node *p=arr[i];
        printf("for %d th index ",i);
        while(p!=NULL)
        {
            printf("%d-->",p->data);
            p=p->next;
        }
        printf("\n");
    }
 
}
