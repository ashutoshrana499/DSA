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
//-5 5 4 3 -2 1 0
void sort(node * list)
{
	node * t=list;
	node * cur=list;
	node * prev=NULL;
	while(cur!=NULL)
	{
		if(cur->val<0)
		{
			node * n=cur->next;
			if(prev!=NULL)
			{
				prev->next = n;
				cur->next=t;
				t=cur;
				cur=n;
			}
			else
			{
				prev=cur;
				cur=cur->next;
			}
		}
		else
		{
			prev=cur;
			cur=cur->next;
		}
	}
	display(t);
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,0);
	list = insert(list,1);
	list = insert(list,-2);
	list = insert(list,3);
	list = insert(list,4);
	list = insert(list,5);
	list = insert(list,-5);
	display(list);
	sort(list);
	return 0;
}