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
    int lengthOfLoop(Node *head) {
        if (!head) return 0;

        Node *slow = head, *fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {  // Loop detected
                // Step 2: Measure loop length
                int count = 1;
                fast = fast->next;

                while (fast != slow) {
                    count++;
                    fast = fast->next;
                }
                return count;
            }
        }
        
        return 0; // No loop
    }
};
