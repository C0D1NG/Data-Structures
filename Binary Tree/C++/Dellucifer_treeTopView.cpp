#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        queue<pair<Node*, int>> q;
        map<int, int> m;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            Node* u = q.front().first;
            int v = q.front().second;
            q.pop();
            if(u->left){
                q.push(make_pair(u->left, v-1));
                if(!m.count(v-1)){
                    m[v-1] = u->left->data;
                }
            }
            if(u->right){
                q.push(make_pair(u->right, v+1));
                if(!m.count(v+1)){
                    m[v+1] = u->right->data;
                }
            }
        }
        for(auto x:m){
            cout<<x.second<<" ";
        }
        cout<<endl;
    }

}; //End of Solution
