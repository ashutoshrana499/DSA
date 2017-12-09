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
void split(node * list,node ** first,node ** sec)
{
	if(list==NULL || list->next==NULL)
	{
		*first=list;
		*sec=NULL;
	}
	else
	{
		node * fast = list->next;
		node * slow = list;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		*first = list;
		*sec = slow->next;
		slow->next=NULL;

	}
}
node * merge(node * a,node *b)
{
	node * t1=a;
	node * t2=b;
	node * c=NULL;
	while(t1 && t2)
	{
		if(t1->val<=t2->val)
		{
			c=insert(c,t1->val);
			t1=t1->next;
		}
		else
		{
			c=insert(c,t2->val);
			t2=t2->next;
		}
	}
	if(t1!=NULL)
		{
			while(t1!=NULL)
			{
				c=insert(c,t1->val);
				t1=t1->next;
			}
		}
	if(t2!=NULL)
	{
		while(t2!=NULL)
		{
			c=insert(c,t2->val);
			t2=t2->next;
		}
	}
	return c;
}
void mergeSort(node ** list)
{
	if(*list==NULL || (*list)->next==NULL)
		return;
	else
	{
		node * a=NULL;
		node * b=NULL;
		split(*list,&a,&b);
		mergeSort(&a);
		mergeSort(&b);
		*list=merge(a,b);
	}

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
	mergeSort(&list);
	display(list);
	return 0;
}