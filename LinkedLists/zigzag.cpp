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
void zigzag(node * list)
{
	char sign='<';
	node * t = list;
	int temp;
	while(t->next!=NULL)
	{
		if(sign=='<')
		{
			if(t->val>t->next->val)
			{
				temp=t->val;
				t->val=t->next->val;
				t->next->val=temp;
			}
			t=t->next;
			sign='>';
		}
		else
		{
			if(t->val<t->next->val)
			{
				temp=t->val;
				t->val=t->next->val;
				t->next->val=temp;	
			}
			t=t->next;
			sign='<';
		}
	}
	display(list);
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,4);
	list = insert(list,3);
	list = insert(list,7);
	list = insert(list,8);
	list = insert(list,6);
	list = insert(list,2);
	list = insert(list,1);
	display(list);
	zigzag(list);
	return 0;
}