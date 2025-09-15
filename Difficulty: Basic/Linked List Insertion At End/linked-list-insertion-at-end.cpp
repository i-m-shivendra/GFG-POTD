/*
class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* temp = new Node(x);
        
        if(head == NULL){
            return temp;
        }
        
        if(head->next == NULL){
            head->next = temp;
            temp->next = NULL;
            return head;
        }
        
        Node* curr = head;
        
        while(curr->next != NULL){
            curr = curr->next;
        }
        
        curr->next = temp;
        
        return head;
    }
};