#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * link;
}NODE;

void printList(NODE *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->link;
    }
    printf("\n");
}
NODE * create(NODE * head,int val)
{
	NODE * temp = (NODE*) malloc(sizeof(struct node));
	temp->data=val;
	temp->link=NULL;
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	else
	{
		NODE * p = head;
		while(p->link!=NULL)
			p=p->link;
		p->link=temp;
		return head;
	}
}

void merge(NODE *l1,NODE**l2)
{
	NODE*p1=l1;
	NODE*p2=*l2;
	NODE * next1;
	NODE * next2;
	while(p1&&p2)
	{
		next1=p1->link;
		next2=p2->link;

		p2->link=next1;
		p1->link=p2;

		p2=next2;
		p1=next1;
		//p1=p1->link;
		//p2=p2->link;
	}
	*l2=p2;
}
int main(int argc, char const *argv[])
{
	NODE * l1 =NULL;
	NODE * l2= NULL;
	l1=create(l1,1);
	l1=create(l1,3);
	l1=create(l1,5);
	l1=create(l1,7);
	l2=create(l2,2);
	l2=create(l2,4);
	l2=create(l2,6);
	l2=create(l2,8);
	l2=create(l2,10);
	l2=create(l2,12);

	merge(l1,&l2);
	printList(l1);
	printList(l2);
	return 0;
}