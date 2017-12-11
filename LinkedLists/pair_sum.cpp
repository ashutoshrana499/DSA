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
void getPairs(node * a,node *b,int sum)
{
	node * t=a;
	unordered_map<int,int>map;
	int i=1;
	while(t!=NULL)
		{
			map.insert(pair<int,int>(t->val,i++));
			t=t->next;
		}
	t=b;
	while(t!=NULL)
	{
		int find = sum-(t->val);
		if(map.count(find)>0)
		{
			cout<<find<<"\t"<<t->val<<"\n";
		}
		t=t->next;
	}

}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,3);
	list = insert(list,1);
	list = insert(list,5);
	list = insert(list,7);
	node * list2 =NULL;
	list2 = insert(list2,3);
	list2 = insert(list2,5);
	list2 = insert(list2,2);
	list2 = insert(list2,8);
	display(list);
	display(list2);
	getPairs(list,list2,6);
	return 0;
}