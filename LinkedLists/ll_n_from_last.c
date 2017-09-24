// C program to find n'th node from end using slow and
// fast pointers
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct Node
{
  int data;
  struct Node* next;
};
 
/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node *head, int n)
{
  struct Node *main_ptr = head;
  struct Node *ref_ptr = head;
 
  int count = 0;
  if(head != NULL)
  {
     while( count < n )
     {
        if(ref_ptr == NULL)
        {
           printf("%d is greater than the no. of "
                    "nodes in list", n);
           return;
        }
        ref_ptr = ref_ptr->next;
        count++;
     } /* End of while*/
 
     while(ref_ptr->next != NULL)
     {
        main_ptr = main_ptr->next;
        ref_ptr  = ref_ptr->next;
     }
     printf("Node no. %d from last is %d ", 
              n, main_ptr->data);
  }
}
 
void push(struct Node** head_ref, int new_data)
{
  /* allocate node */
  struct Node* new_node =
          (struct Node*) malloc(sizeof(struct Node));
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*head_ref);    
 
  /* move the head to point to the new node */
  (*head_ref)    = new_node;
}
 
/* Drier program to test above function*/
int main()
{
  /* Start with the empty list */
  struct Node* head = NULL;
  for(int i=10;i>=1;i--)
    push(&head,i);
 
  printNthFromLast(head, 4);
}