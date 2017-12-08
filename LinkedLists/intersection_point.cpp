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
	node * list1,*list2;
	list1=list2=NULL;
	list1 = insert(list1,1);
	list1 = insert(list1,2);
	list1 = insert(list1,3);
	list1 = insert(list1,5);
	list1 = insert(list1,6);
	int c1 = 5;
	int c2 = 4;
	int d=c1-c2;
	list2 = insert(list2,9);
	list2 = insert(list2,7);
	list2->next->next=list1->next->next->next;
	display(list1);
	display(list2);
	node * t1=list1;
	while(d!=0)
		{
			t1=t1->next;
			d--;
		}
	node* t2=list2;
	while(t1 && t2)
	{
		if(t1==t2)
		{
			cout<<"intersection point found "<<t1->val;
			break;
		}
		t1=t1->next;
		t2=t2->next;
	}
	return 0;
}