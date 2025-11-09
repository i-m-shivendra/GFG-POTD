#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int left = 0, res = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < n; right++) {
            freq[arr[right]]++;

            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }

            // All subarrays ending at 'right' with at most k distinct elements
            res += (right - left + 1);
        }

        return res;
    }
};
