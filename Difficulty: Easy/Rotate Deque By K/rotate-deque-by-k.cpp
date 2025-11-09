class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;

        k %= n;
        if (k == 0) return;

        if (type == 1) {
            // Right rotation: move back → front (k times)
            while (k--) {
                int val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            }
        }
        else {
            // Left rotation: move front → back (k times)
            while (k--) {
                int val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
        }
    }
};
