#include <vector>
using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<int, int> freq;

        while (j < n) {
            freq[arr[j]]++; // include current element

            // shrink window if more than 2 distinct elements
            while (freq.size() > 2) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0) freq.erase(arr[i]);
                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
