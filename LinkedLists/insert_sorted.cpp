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
node * insertSorted(node * list,int n)
{
	node * p=list;
	node * temp = new node;
	temp->next=NULL;
	temp->val=n;
	if(p->val>n)
	{
		temp->next=p;
		return temp;
	}
	else
	{
		while(p->next && p->next->val<n)
			p=p->next;
		temp->next = p->next;
		p->next=temp;
		return list;
	}
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,5);
	list = insert(list,6);
	display(list);
	int n;
	//cin>>n;
	list = insertSorted(list,4);
	display(list);
	return 0;
}