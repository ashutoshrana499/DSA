#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	int val;
	struct node * next;
}node;

node * insert(node * list,int v)
{
	node* temp = new node;
	temp->val = v;
	temp->next=NULL;
	if(list==NULL)
		return temp;
	else
	{
		node* p = list;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
		return list;
	}
}
void display(node * list)
{
	node * p=list;
	while(p!=NULL)
		{
			printf("%d\t",p->val);
			p=p->next;
		}
	printf("\n");
}
node * checkLoop(node* list)
{
	node * p=list;
	node * q =list;
	while(p!=NULL && q!=NULL && q->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
		if(q==p)
			return p;
	}
}
void countLoop(node * list)
{
	node * loop_node = checkLoop(list);
	int count = 0;
	node * p = loop_node;
	do
	{
		count++;
		p=p->next;
	}while(p!=loop_node);
	cout<<count;
}

int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,5);
	list->next->next->next->next=list->next;
	//display(list);
	countLoop(list);
	return 0;
}