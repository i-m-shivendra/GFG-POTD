/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
public:
    int sum = 0;

    void transform(Node* root) {
        if (!root) return;

        // Reverse inorder: right -> root -> left
        transform(root->right);

        int original = root->data;
        root->data = sum;
        sum += original;

        transform(root->left);
    }

    void transformTree(Node *root) {
        sum = 0;
        transform(root);
    }
};
