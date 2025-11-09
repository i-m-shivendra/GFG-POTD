#include <vector>
using namespace std;

class Solution {
public:
    long long subarraySum(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        for(int i = 0; i < n; i++) {
            total += (long long)arr[i] * (i + 1) * (n - i);
        }
        return total;
    }
};
