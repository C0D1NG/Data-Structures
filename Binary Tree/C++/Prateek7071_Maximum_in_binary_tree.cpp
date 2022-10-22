#include<iostream>

using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node* CreateNew(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}


node* InsertIntoTree(node* root, int data)
{

	node *temp = CreateNew(data);
	node *t = new node;
	t = root;

	if(root == NULL)
		root = temp;
	else
	{

		while(t != NULL)
		{
			if(t->data < data )
			{
				if(t->right == NULL)
				{

					t->right = temp;
					break;
				}

				t = t->right;
			}

			else if(t->data > data)
			{
				if(t->left == NULL)
				{

					t->left = temp;
					break;
				}

				t = t->left;
			}
		}
	}
	return root;
}


int main()
{
	char ch;
	int n, i, a[20]={89, 22, 95, 1, 9, 54, 72, 66, 75, 80, 18, 24, 35, 90, 38, 41, 49, 81, 33, 103};
	node *root = new node;
	root = NULL;
	cout<<"\nData set:\n";
	for(i = 0; i < 20; i++)
	{
		cout<<a[i]<<" ";
		root = InsertIntoTree(root, a[i]);
	}

	cout<<"\n\nThe maximum element of the given data set is ";
	i = 0;
	while(root->right != NULL)
	{
		i++;
		root = root->right;
	}
	cout<<root->data<<" found at "<<i<<" depth from the root.";

	return 0;
}
