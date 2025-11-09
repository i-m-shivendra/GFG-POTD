/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;

        // Process left and right subtrees first
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);

        // Now process root
        if (root->data < l)
            return root->right;   // discard root and left subtree

        if (root->data > r)
            return root->left;    // discard root and right subtree

        return root; // valid node
    }
};
