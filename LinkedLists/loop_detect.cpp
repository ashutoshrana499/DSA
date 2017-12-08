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
bool checkLoop(node* list)
{
	node * p=list;
	node * q =list;
	while(p!=NULL && q!=NULL && q->next!=NULL)
	{
		p=p->next;
		q=q->next->next;
		if(q==p)
			return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,5);
	list->next->next->next=list;
	//display(list);
	bool flag = checkLoop(list);
	if(flag)
		cout<<"loop";
	else
		cout<<"no loop";
	return 0;
}