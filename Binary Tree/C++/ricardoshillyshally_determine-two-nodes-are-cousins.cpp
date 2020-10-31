#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

// Data structure to store a Binary Tree node along
// with its level and parent information
struct NodeInfo
{
	int key;
	int level;
	Node* parent;
};

// Perform in-order traversal of the binary tree and update x and y
void inorder(Node* root, Node *parent, int level, NodeInfo &x, NodeInfo &y)
{
	// base case: tree is empty
	if (root == nullptr)
		return;

	// traverse left subtree
	inorder(root->left, root, level + 1, x, y);

	// if first element is found, save its level and parent node
	if (root->key == x.key)
	{
		x.level = level;
		x.parent = parent;
	}

	// if second element is found, save its level and parent node
	if (root->key == y.key)
	{
		y.level = level;
		y.parent = parent;
	}

	// traverse right subtree
	inorder(root->right, root, level + 1, x, y);
}

// Function to determine if two given nodes are cousins of each other
bool iterative(Node* root, int elem1, int elem2)
{
	// return if tree is empty
	if (root == nullptr)
		return false;

	int level = 1;				// level of root is 1
	Node* parent = nullptr;		// parent of root is null

	NodeInfo x = {elem1, level, parent};
	NodeInfo y = {elem2, level, parent};

	// perform in-order traversal of the array and update x and y
	inorder(root, nullptr, 1, x, y);

	// return false if x and y have different level or same parent
	if (x.level != y.level || x.parent == y.parent)
		return false;

	return true;
}

int main()
{
	Node* root = nullptr;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	if (iterative(root, 5, 6))
		cout << "Given nodes are cousins";
	else
		cout << "Given nodes are not cousins";

	return 0;
}
