#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

 struct node *create()
{
    int x;
   struct node*newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter data be entered (-1 for  no node)");
   printf("\n");
   scanf("%d",&x);
if(x==-1)
   {
       return NULL;
   }
   newnode->data=x;
printf("Enter left child of %d",x);
printf("\n");
newnode->left=create();
printf("Enter right child of %d",x);
printf("\n");
newnode->right=create();
return newnode;
}

void preorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void postorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
int main (void)
{
    struct node*root=NULL;
    root=create();
    
    printf("PREORDER ");
    preorder(root);
    printf("\n");
    printf("INORDER ");
    inorder(root);
    printf("\n");

    printf("POSTORDER ");
    postorder(root);
    printf("\n");

}
