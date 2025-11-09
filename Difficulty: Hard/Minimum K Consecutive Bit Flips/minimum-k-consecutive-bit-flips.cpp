class Solution {
public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flips = 0, flipCount = 0; // flipCount tracks number of flips affecting current index

        for (int i = 0; i < n; i++) {
            // If the flip effect at this index ends
            if (i >= k && arr[i - k] > 1) {
                flipCount--;
                arr[i - k] -= 2; // revert to original 0/1
            }

            if ((arr[i] + flipCount) % 2 == 0) { // current bit is 0 after flips
                if (i + k > n) return -1;
                flips++;
                flipCount++;
                arr[i] += 2; // mark this flip
            }
        }
        return flips;
    }
};
