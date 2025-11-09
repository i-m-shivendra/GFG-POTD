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
    // Fill stack with predecessors
    void fillPre(Node* root, int target, stack<Node*>& st) {
        while (root) {
            if (root->data <= target) {
                st.push(root);
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

    // Fill stack with successors
    void fillSuc(Node* root, int target, stack<Node*>& st) {
        while (root) {
            if (root->data > target) {
                st.push(root);
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }

    // Get next predecessor (largest smaller than current)
    int getNextPre(stack<Node*>& st) {
        Node* curr = st.top();
        st.pop();
        int val = curr->data;
        curr = curr->left;
        while (curr) {
            st.push(curr);
            curr = curr->right;
        }
        return val;
    }

    // Get next successor (smallest greater than current)
    int getNextSuc(stack<Node*>& st) {
        Node* curr = st.top();
        st.pop();
        int val = curr->data;
        curr = curr->right;
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        return val;
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> result;
        if (!root || k == 0) return result;

        stack<Node*> pre, suc;

        // Fill predecessor and successor stacks
        fillPre(root, target, pre);
        fillSuc(root, target, suc);

        // If top of both stacks are same (equal values), pop one to avoid duplicates
        if (!pre.empty() && !suc.empty() && pre.top()->data == suc.top()->data) {
            getNextPre(pre);
        }

        // pick the closest k values
        while (k--) {
            if (pre.empty() && suc.empty()) break;

            if (pre.empty()) {
                result.push_back(getNextSuc(suc));
            } else if (suc.empty()) {
                result.push_back(getNextPre(pre));
            } else {
                int preVal = pre.top()->data;
                int sucVal = suc.top()->data;

                if (abs(preVal - target) <= abs(sucVal - target))
                    result.push_back(getNextPre(pre));
                else
                    result.push_back(getNextSuc(suc));
            }
        }

        return result;
    }
};
