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
 
int max(int a,int b)
{
    return (a>b)? a:b;
}
int height(NODE *root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
 
int diameter(NODE *root){
    if(root==NULL)
        return 0;
 
    int lheight=height(root->left);
 
    int rheight=height(root->right);
 
    int ldia=diameter(root->left);
 
    int rdia=diameter(root->right);
 
    return max(1+lheight+rheight,max(ldiam,rdiam));
}
int main(int argc, char const *argv[])
{
    NODE * root=NULL;
    root = create();
    printf("%d\n",diameter(root) );
    return 0;
}
