class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> last(10, -1);

        // store last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        // try to find the best swap
        for (int i = 0; i < n; i++) {
            int current = s[i] - '0';

            // look for a larger digit from 9 down to current+1
            for (int d = 9; d > current; d--) {
                if (last[d] > i) {
                    // swap
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }

        return s; // no swap improves it
    }
};
