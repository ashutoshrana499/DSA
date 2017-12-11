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
void partition(node * list,int key)
{
	node * less=NULL;
	node * more = NULL;
	node * equal=NULL;
	node * t=list;
	while(t!=NULL)
	{
		if(t->val<key)
			less = insert(less,t->val);
		else if(t->val==key)
			equal = insert(equal,t->val);
		else 
			more = insert(more,t->val);
		t=t->next;
	}
	if(less!=NULL)
	{
		t=less;
		while(t->next!=NULL)
			t=t->next;
		t->next=equal;
	}
	t=equal;
	while(t->next!=NULL)
		t=t->next;
	t->next=more;
	if(less!=NULL)
		display(less);
	else
		display(equal);
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,4);
	list = insert(list,3);
	list = insert(list,1);
	list = insert(list,5);
	list = insert(list,2);
	list = insert(list,3);
	display(list);
	partition(list,5);
	return 0;
}