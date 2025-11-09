/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head) return head;

        int count[3] = {0, 0, 0};
        Node* temp = head;

        // Count occurrences of 0, 1, and 2
        while (temp) {
            count[temp->data]++;
            temp = temp->next;
        }

        temp = head;

        // Overwrite values in sorted order
        int i = 0;
        while (temp) {
            if (count[i] == 0) i++;
            else {
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }

        return head;
    }
};
