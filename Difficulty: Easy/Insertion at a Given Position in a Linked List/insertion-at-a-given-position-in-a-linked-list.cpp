/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        Node* temp = new Node(val);
        
        if(pos == 1){
            temp->next = head;
            return temp;
        }
        
        Node* curr = head;
        
        for(int i=1;i<=pos-2 && curr!=NULL;i++){
            curr = curr->next;
        }
        
        if(curr == NULL){
            return head;
        }
        
        temp->next = curr->next;
        curr->next = temp;
        
        return head;
    }
};