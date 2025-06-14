/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* temp = new Node(x);
        
        if(head == NULL){
            return temp;
        }
        
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr -> next;
        }
        curr->next = temp;
        return head;
    }
};