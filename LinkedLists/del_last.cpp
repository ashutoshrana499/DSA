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
void del(node * list,int key)
{
	node * t=list;
	node * d=list;
	node * prev = NULL;
	while(t!=NULL && t->next!=NULL)
	{
		if(t->next->val==key)
			prev=t;
		t=t->next;
	}
	if(prev!=NULL)
	{
		d=prev->next;
		if(d!=NULL)
		{
			prev->next=d->next;
			d->next=NULL;
			delete d;
		}
		else if(d==NULL)
		{	
			prev->next=NULL;
		}
	}
	else
	{
		d=list;
		list=list->next;
		d->next=NULL;
		delete d;
	}
	display(list);

}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,0);
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,2);
	list = insert(list,5);
	list = insert(list,4);
	display(list);
	del(list,0);
	return 0;
}