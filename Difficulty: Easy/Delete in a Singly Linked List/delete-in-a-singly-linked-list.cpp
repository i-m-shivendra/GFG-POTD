/*
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        if(x == 1){
            Node* temp = head->next;
            delete head;
            return temp;
        }
        
        Node* curr = head;
        
        for(int i=1;i<x-1;i++){
            curr = curr->next;
        }
        
        curr -> next = curr->next->next;
        return head;
    }
};