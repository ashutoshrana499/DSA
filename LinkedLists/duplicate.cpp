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

int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,1);
	list = insert(list,5);
	list = insert(list,5);
	list = insert(list,1);
	list = insert(list,6);
	display(list);
	unordered_map<int,int> map;
	node *t=list;
	node * prev=NULL;
	int i=1;
	while(t!=NULL)
	{
		if(map.count(t->val)>0)
			prev->next=t->next;
		else
		{
			map.insert(pair<int,int>(t->val,i));
			i++;
			prev=t;
		}
		t=t->next;
	}
	display(list);
	return 0;
}