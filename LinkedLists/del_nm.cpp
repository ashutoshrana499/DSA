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
//delete n after m
//1 2 3 4 5 6 7 8 9             2 3
void delete_mn(node * list,int m,int n)
{
	int m_c=m;
	int n_c=n;
	node * prev=NULL;
	node* cur=list;
	while(cur->next!=NULL)
	{
		for(int c1=0;c1<m_c && cur!=NULL;c1++)
			{
				prev = cur;
				if(cur!=NULL)
					cur=cur->next;
			}
		if(cur==NULL)
			break;
		node * t;
		for(int c2=0;c2<n_c && cur!=NULL;c2++)			
			{

				t=cur;
				cur=cur->next;
				t->next=NULL;
				delete t;
			}
		prev->next = cur;
		n_c=n;
		m_c=m;
		if(cur==NULL)
				break;
	}
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	for(int i=1;i<=9;i++)
		list=insert(list,i);
	display(list);
	delete_mn(list,2,3);
	display(list);
	return 0;
}