/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
   public:
    
    void inorder(Node*root,vector<int>&res){
        
        if(root==nullptr)   return;
        
        inorder(root->left,res);
        res.push_back(root->data);
        inorder(root->right,res);
        
    }
    
    int findMedian(Node* root) {
        // Code here
        vector<int>res;
        
        inorder(root,res);
        
        if(res.empty()) return -1;
        
        int n=res.size();
        if(n%2==0) return res[(n/2)-1];
        
        if(n%2==1) return res[((n+1)/2)-1];
            
        
        
        
    }
};