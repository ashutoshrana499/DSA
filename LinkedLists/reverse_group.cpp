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
//1->2->3->4->5->NULL
//
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
    if(n!=NULL)
    	list->next=reverse(n,k);
    return prev;
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
	display(list);
	list=reverse(list,2);
	display(list);
	return 0;
}