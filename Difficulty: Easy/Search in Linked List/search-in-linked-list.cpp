/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
        // Code here
        Node* curr = head;
        
        while(curr != NULL){
            if(curr->data == key){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};
