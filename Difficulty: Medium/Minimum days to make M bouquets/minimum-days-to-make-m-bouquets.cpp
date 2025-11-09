#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDaysBloom(vector<int>& bloomDay, int k, int m) {
        int n = bloomDay.size();
        if (n < m * k) return -1; // not enough flowers

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, k, m, mid)) {
                ans = mid;
                right = mid - 1; // try to find smaller day
            } else {
                left = mid + 1; // need more days
            }
        }

        return ans;
    }

private:
    bool canMake(vector<int>& bloomDay, int k, int m, int day) {
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
};
