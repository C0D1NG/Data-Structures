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

//O (n) complexity traversal for all the binary tree with n = number of nodes
Node* lowestCommonAncestor(Node* root, int n1, int n2) {
	if (root == nullptr) return nullptr;
	if (root->value == n1 || root->value == n2) return root;

	Node* left = lowestCommonAncestor(root->left, n1, n2);
	Node* right = lowestCommonAncestor(root->right, n1, n2);

	if (left != nullptr && right != nullptr) return root;
	if (left == nullptr && right == nullptr) return nullptr;

	//Else we arrive to the ancestor
	if (left != nullptr) return left;
	else return right;
}

int main()
{
	//Root
	Node* root = new Node(3);

	//Left side
	root->left = new Node(6);
	root->left->left = new Node(2);
	root->left->right = new Node(11);
	root->left->right->left = new Node(9);
	root->left->right->right = new Node(5);

	//Right side
	root->right = new Node(8);
	root->right->right = new Node(13);
	root->right->right->left = new Node(7);

	std::cout << "LCA (2,5): " << lowestCommonAncestor(root, 2, 5)->value << std::endl;
	std::cout << "LCA (9,5): " << lowestCommonAncestor(root, 9, 5)->value << std::endl;
	std::cout << "LCA (9,3): " << lowestCommonAncestor(root, 9, 3)->value << std::endl;

	return 0;
}