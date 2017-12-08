#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	int val;
	struct node * next;
}node;

node * push(node * list,int v)
{
	node* temp = new node;
	temp->val = v;
	temp->next=NULL;
	if(list==NULL)
		return temp;
	else
	{
		temp->next=list;
		return temp;
	}
}
node * addSameSize(node * a,node *b,int * car)
{
	if(a==NULL)
		return NULL;
	int sum=0;

	node * c = new node;
	c->next=addSameSize(a->next,b->next,car);
	sum=a->val+b->val+ (*car);
	*car = sum/10;
	sum=sum%10;
	c->val=sum;
	return c;
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
void addCarryToRemaining(node* head1, node* cur, int* carry, node** result)
{
    int sum;
 
    // If diff. number of nodes are not traversed, add carry
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);
 
        sum = head1->val + *carry;
        *carry = sum/10;
        sum %= 10;
        // add this node to the front of the result
        push(*result, sum);
    }
}
int main(int argc, char const *argv[])
{
	node *a,*b,*c;
	a=b=c=NULL;
	a = push(a,9);
	a = push(a,9);
	a = push(a,8);
	b = push(b,8);
	b = push(b,1);
	display(a);
	display(b);
	int len1=3;
	int len2=2;
	int car=0;
	if(len1!=len2)
	{
		int diff = abs(len1 - len2);
		node * cur;
        if (len1 < len2)
           {
           	node * t = b;
           	b=a;
           	a=t;
           }
 
        // move diff. number of nodes in first list
        for (cur = a; diff--; cur = cur->next); 
        // get addition of same size lists
        c = addSameSize(cur, b, &car);
 
        // get addition of remaining first list and carry
        addCarryToRemaining(a, cur, &car, &c);
        if(car)
				c=push(c,car);
		display(c);
	}
	else
	{
		c=addSameSize(a,b,&car);
		if(car)
			{
				printf("%d\n",car);
				c=push(c,car);
			}
		display(c);
	}
	return 0;
}