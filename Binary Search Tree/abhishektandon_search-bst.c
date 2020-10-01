#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BSTnode {
	int info;
	struct BSTnode* left;
	struct BSTnode* right;
};

typedef struct BSTnode* nodeptr;

nodeptr getnode(int data) {
	nodeptr p=(nodeptr)malloc(sizeof(struct BSTnode));
	if(p==NULL)
		printf("Could not create node\n");
	
	p->info=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void freenode(nodeptr p) {
	free(p);
}


bool search(nodeptr root,int data) {
	if(root==NULL)
		return false;
    if(root->info==data)
		return true;
	else if(root->info>=data)
		return search(root->left,data);
	else
		return search(root->right,data);
}

nodeptr insert(nodeptr root, int data) {
	if(root==NULL) {
	root=getnode(data);
	return root;
	}
	else if((root->info)>=data)
	root->left = insert((root)->left,data);
	else
	root->right = insert((root)->right,data);
	return root;
}

int main() {
	nodeptr root=NULL;
	root=insert(root,5);
	root=insert(root,6);
	root=insert(root,4);
	printf("%d %d %d",root->info,((root->right))->info,((root->left))->info);
	if(search(root,5))
		printf("\nFound\n");
	if(search(root,8))
		printf("Found\n");
    else
        printf("Not found\n");
	return 0;
}
