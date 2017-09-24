#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node * link;
}NODE;

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
NODE * insert_sorted(NODE * head,int val)
{
	NODE * temp = (NODE*) malloc(sizeof(struct node));
	temp->data=val;
	temp->link=NULL;

	NODE * p = head;
	while(p->link->data<val)
		p=p->link;
	NODE * next = p->link;
	p->link = temp;
	temp->link= next;
	return head;
}

int main(int argc, char const *argv[])
{
	NODE * head =NULL;
	head=create(head,1);
	head=create(head,2);
	head=create(head,3);
	head=create(head,5);
	head=create(head,6);
	head=insert_sorted(head,4);

	NODE * p = head;
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=p->link;
	}

	return 0;
}