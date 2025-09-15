/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        if(head == NULL){
            return NULL;
        }
        
        if(head->next == NULL){
            return 1;
        }
        
        int count = 0;
        Node* curr = head;
        
        while(curr != NULL){
            count += 1;
            curr = curr->next;
        }
        return count;
    }
};