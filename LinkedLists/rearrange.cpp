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
void reverse(node** list)
{
     node* prev   = NULL;
     node* cur = *list;
     node* n=*list;
    while (cur != NULL)
    {
        n  = cur->next;  
        cur->next = prev;   
        prev = cur;
        cur = n;
    }
    *list = prev;
}
node * getMid(node * list)
{
	node * slow=list;
	node * fast=list;
	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
		if(fast->next!=NULL)
			fast=fast->next;
	}
	return slow;
}
node* merge(node *a,node *b)
{
	node * c=NULL;
	node *t1=a;
	node *t2=b;
	while(t1&&t2)
	{
		c=insert(c,t1->val);
		c=insert(c,t2->val);
		t1=t1->next;
		t2=t2->next;
	}
	if(t1!=NULL)
	{
		while(t1!=NULL)
		{
			c=insert(c,t1->val);
			t1=t1->next;
		}
	}
	return c;
}
void splitReverse(node * list,node ** a,node **b)
{
	node * mid = getMid(list);
	*a=list;
	*b=mid->next;
	mid->next=NULL;
	reverse(b);
	node * final = merge(*a,*b);
	display(final);
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,4);
	list = insert(list,5);
	display(list);
	node *a=NULL;
	node *b=NULL;
	splitReverse(list,&a,&b);
	return 0;
}