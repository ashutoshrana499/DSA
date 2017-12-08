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
			return q;
	}
}
void removeLoop(node * list)
{
	node * loop_tail = checkLoop(list);
	int k=0;
	node * t=loop_tail;
	while(t!=NULL)
	{
		t=t->next;
		k++;
		if(t==loop_tail)
			break;
	}
	t =list;
	node * kt=list;
	while(k--)
		kt=kt->next;
	while(kt!=t)
	{
		kt=kt->next;
		t=t->next;
	}
	cout<<t->val<<endl;
	loop_tail->next=NULL;
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,4);
	list->next->next->next->next=list->next;
	removeLoop(list);
	display(list);
	return 0;
}