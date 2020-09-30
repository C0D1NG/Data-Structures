#include <iostream>

struct Node
{
	int value;
	Node* left;
	Node* right;
	Node(int value)
	{
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}

};

Node* BSTSearch(Node* root, int value) {
	if (root == nullptr || root->value == value)
		return root;

	if (root->value < value)
		return BSTSearch(root->right, value);
 
	return BSTSearch(root->left, value);
}

int main()
{
	//Root
	Node* root = new Node(15);

	root->left = new Node(10);
	root->left->left = new Node(8);
	root->left->right = new Node(12);

	root->right = new Node(20);
	root->right->left = new Node(16);
	root->right->right = new Node(22);

	std::cout << "The value " << 5 << (BSTSearch(root, 5) == nullptr ? " was not found" : " was found") << std::endl;
	std::cout << "The value " << 22 << (BSTSearch(root, 22) == nullptr ? " was not found" : " was found") << std::endl;
	std::cout << "The value " << 1 << (BSTSearch(root, 1) == nullptr ? " was not found" : " was found") << std::endl;
	std::cout << "The value " << 8 << (BSTSearch(root, 8) == nullptr ? " was not found" : " was found") << std::endl;


	return 0;
}