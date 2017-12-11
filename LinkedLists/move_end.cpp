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
void moveEnd(node * list,int key)
{
	node * pkey=list;
	node * p = list;
	while(p!=NULL)
	{
		if(pkey->val!=key)
			pkey=pkey->next;
		if(p!=pkey && p->val!=key)
		{
			int t=p->val;
			p->val=pkey->val;
			pkey->val=t;
			pkey=pkey->next;
		}
		p=p->next;
	}
	display(list);
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,10);
	list = insert(list,20);
	list = insert(list,10);
	list = insert(list,30);
	list = insert(list,40);
	list = insert(list,10);
	list = insert(list,60);
	display(list);
	moveEnd(list,10);
	return 0;
}