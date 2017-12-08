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
void reverse(node ** list)
{
	node * cur=*list;
	node* n = *list;
	node * prev=NULL;
	while(cur!=NULL)
	{
		n=cur->next;
		cur->next=prev;
		prev=cur;
		cur=n;
	}
	*list=prev;
}
bool compare(node* l1,node *l2)
{
	node *t1=l1;
	node* t2=l2;
	while(t1&&t2)
	{
		if(t1->val==t2->val)
		{
			t1=t1->next;
			t2=t2->next;
		}
		else 
			return false;
	}
	return true;
}
bool checkPalin(node* list)
{
	node * mid = NULL;
	node* slow=list;
	node* fast=list;
	node * prev_slow=list;
	while(fast!=NULL && fast->next!=NULL)
	{
		prev_slow=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	if(fast!=NULL)
	{
		mid=slow;
		slow=slow->next;
	}
	node * second = slow;
	prev_slow->next=NULL;
	reverse(&second);
	bool res = compare(list,second);
	reverse(&second);
	if(mid!=NULL)
	{
		prev_slow->next=mid;
		mid->next=second;
	}
	else
		prev_slow->next=second;

	return res;

}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,1);
	list = insert(list,4);
	display(list);
	bool flag = checkPalin(list);
	if(flag)
		cout<<"palin";
	else
		cout<<"no palin";
	return 0;
}