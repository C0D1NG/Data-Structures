#include <bits/stdc++.h>
using namespace std;
//ADT of the Tree Nodes
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

//finding height of the tree
//the maximum height among the left and right subtree is taken
int findHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh, rh;
    lh = findHeight(root->left);
    rh = findHeight(root->right);
    return max(lh, rh) + 1;
}

int main()
{
    //Creating the binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->left->right->right->left = new TreeNode(1);
    root->left->right->right->right = new TreeNode(2);
    root->left->right->right->right->right = new TreeNode(2);
    root->left->right->right->right->right->left = new TreeNode(1);
    root->left->right->right->right->right->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << "The Binary Tree is created\n";
    cout << "The Height of the binary tree is:  " << findHeight(root) << "\n";
    return 0;
}