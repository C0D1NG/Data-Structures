#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode* root,vector<int>& v) {
    if(root==NULL) return;
    inorderTraversal(root->left,v);
    v.push_back(root->val);
    inorderTraversal(root->right,v);   
}

int main(){

    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(4);
    t->left->right = new TreeNode(6);
    t->right = new TreeNode(2);
    t->right->left = new TreeNode(3);
    t->right->right = new TreeNode(5);

    vector<int>v;
    inorderTraversal(t,v);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}