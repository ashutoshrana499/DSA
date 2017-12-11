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
void removeDup(node * list)
{
	node * dummy = new node;
	dummy->val=-1;
	dummy->next=list;
	node * cur=list;
	node * prev = dummy;
	while(cur!=NULL)
	{
		while(cur->next!=NULL && prev->next->val == cur->next->val)
			cur=cur->next;

		if(prev->next == cur)
			prev = prev->next;
		else
			prev->next=cur->next;
		cur=cur->next;
	}
	display(dummy->next);
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,23);
	list = insert(list,23);
	list = insert(list,28);
	list = insert(list,28);
	list = insert(list,35);
	list = insert(list,43);
	list = insert(list,53);
	list = insert(list,53);
	display(list);
	removeDup(list);
	return 0;
}