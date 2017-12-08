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
node* reverse(node* list,int k)
{
     node* prev   = NULL;
     node* cur = list;
     node* n=list;
    int c=0;
    while (cur != NULL && c<k)
    {
        n  = cur->next;  
        cur->next = prev;   
        prev = cur;
        cur = n;
        c++;
    }
    list->next=cur;
    return prev;
}
//1->2->3->4->5->6->7->8->9->NULL
void altreverseK(node * list,int k)
{
	node *l;
	node * prev;
		node * p = reverse(list,k);
	display(p);
	l = p;
	int c=k;
	node * prev;
	cout<<list->val<<endl;
	while(c>=0)
		{
			prev = list;
			list=list->next;
			c--;
		}
	while(prev!=NULL)
	{
		cout<<list->val<<endl;
	prev->next=reverse(list,k);
	}
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,2);
	list = insert(list,3);
	list = insert(list,4);
	list = insert(list,5);
	list = insert(list,6);
	list = insert(list,7);
	list = insert(list,8);
	list = insert(list,9);
	display(list);
	 altreverseK(list,2);
	//display(p);
	return 0;
}