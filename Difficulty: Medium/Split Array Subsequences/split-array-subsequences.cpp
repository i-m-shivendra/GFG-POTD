class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq, need;

        // Count frequencies
        for (int x : arr) freq[x]++;

        for (int x : arr) {
            if (freq[x] == 0) continue;

            // Case 1: extend an existing subsequence
            if (need[x] > 0) {
                need[x]--;
                need[x + 1]++;
                freq[x]--;
            } 
            else {
                // Case 2: start a new subsequence of length k
                bool ok = true;
                for (int i = 0; i < k; i++) {
                    if (freq[x + i] == 0) { 
                        ok = false; 
                        break; 
                    }
                }
                if (!ok) return false;

                // Deduct k consecutive numbers
                for (int i = 0; i < k; i++) {
                    freq[x + i]--;
                }

                // New subsequence will need x+k next
                need[x + k]++;
            }
        }
        return true;
    }
};
