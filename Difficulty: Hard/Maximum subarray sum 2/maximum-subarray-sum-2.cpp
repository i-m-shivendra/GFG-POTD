class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> prefix(n+1, 0);
        for (int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + arr[i];

        multiset<long long> window;
        int ans = INT_MIN;

        for (int i = a-1; i < n; i++) {
            if (i - b >= 0)
                window.erase(window.find(prefix[i-b]));
            
            window.insert(prefix[i - a + 1]);

            ans = max(ans, (int)(prefix[i+1] - *window.begin()));
        }

        return ans;
    }
};
