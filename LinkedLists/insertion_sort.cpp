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
void insertInPlace(node ** sorted,node * cur)
{
	if(*sorted==NULL || cur->val<=(*sorted)->val)
	{
		cur->next=(*sorted);
		*sorted=cur;
	}
	else
	{
		node * p = *sorted;
		while(p->next!=NULL && p->next->val<cur->val)
			p=p->next;
		cur->next=p->next;
		p->next=cur;
	}
}
void insertionSort(node * list)
{
	node * sorted=NULL;
	node * cur=list;
	while(cur!=NULL)
	{
		node * n = cur->next;
		insertInPlace(&sorted,cur);
		cur=n;
	}
	display(sorted);
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,5);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,1);
	list = insert(list,4);
	display(list);
	insertionSort(list);
	return 0;
}