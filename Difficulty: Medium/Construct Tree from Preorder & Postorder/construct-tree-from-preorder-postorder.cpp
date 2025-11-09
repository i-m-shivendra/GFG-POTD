/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    Node* constructTree(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        int preIndex = 0, postIndex = 0;
        return build(pre, post, preIndex, postIndex, n);
    }
    
    Node* build(vector<int> &pre, vector<int> &post, int &preIndex, int &postIndex, int n) {
        Node* root = new Node(pre[preIndex++]);
        
        // if leaf node, return
        if (root->data == post[postIndex]) {
            postIndex++;
            return root;
        }
        
        // build left subtree
        root->left = build(pre, post, preIndex, postIndex, n);
        
        // build right subtree
        root->right = build(pre, post, preIndex, postIndex, n);
        
        // now root node should match post[postIndex]
        postIndex++;
        
        return root;
    }
};
