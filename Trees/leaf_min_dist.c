#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}NODE;
NODE * create()
{
    NODE * temp;
    int x;
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    temp=(NODE *)malloc(sizeof(struct node));
    temp->val=x;
    printf("\nenter left");
    temp->left=create();
    printf("\nenter right");
    temp->right=create();
    return temp;
}
void inorder(NODE * root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d\t",root->val);
        inorder(root->right);
    }
}
int min=999,count=0;
void findMinLevel(NODE *root) 
{
    if(root==NULL)
        return;
    else
    {
        if(root->left!=NULL||root->right!=NULL)
        {
            count++;
            findMinLevel(root->left);
            count++;
            findMinLevel(root->right);
            count++;
        }
        else
        {
            if(count<min)
            {
                min=count;
                //printf("%d\n",min);
                count=0;
            }
        }
    }
}
int sum=0;
int c=0;
void post(NODE * root)
{
    if(root==NULL)
        return;
    else
    {
        if(root->right||root->left)
        {
            c++;
            post(root->left);
            //c++;
            post(root->right);
            //c++;
        }
        else
        {
             if(c==min)
            {
                sum=sum+root->val;
                c=0;
            }
            else
                c=0;
        }
    }
}
int main(int argc, char const *argv[])
{
    NODE * root=NULL;
    root = create();
    //inorder(root);
    findMinLevel(root);
    printf("%d\n",min);
    post(root);
    printf("%d\n",sum);
    return 0;
}
