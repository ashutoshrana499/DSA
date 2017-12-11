#include <bits/stdc++.h>
using namespace std;
typedef uintptr_t ut;
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
void reverse(node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
     while (current != NULL)
    {
        // This expression evaluates from left to right
        // current->next = prev, changes the link fron
        //                 next to prev node
        // prev = current, moves prev to current node for
        //        next reversal of node
        // This example of list will clear it more 1->2->3->4
        // initially prev = 1, current = 2
        // Final expression will be current = 1^2^3^2^1,
        // as we know that bitwise XOR of two same
        // numbers will always be 0 i.e; 1^1 = 2^2 = 0
        // After the evaluation of expression current = 3 that
        // means it has been moved by one node from its
        // previous position
        current = (struct node *) ((ut)prev^(ut)current^(ut)(current->next)^
                                  (ut)(current->next = prev)^
                                  (ut)(prev = current));
    }
 
    *head_ref = prev;
}
int main(int argc, char const *argv[])
{
	node * list=NULL;
	list = insert(list,1);
	list = insert(list,4);
	list = insert(list,3);
	list = insert(list,1);
	list = insert(list,5);
	list = insert(list,2);
	list = insert(list,3);
	display(list);
	reverse(&list);
	display(list);
	return 0;
}