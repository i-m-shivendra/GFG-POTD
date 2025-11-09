class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {

        int n = jobs.size();

        // Sort jobs by end time
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        vector<int> dp(n, 0);

        dp[0] = jobs[0][2];  // profit of first job

        for(int i = 1; i < n; i++){
            
            int include = jobs[i][2]; // profit of current job

            // Binary search the last job that ends before jobs[i] starts
            int l = 0, r = i - 1, idx = -1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(jobs[mid][1] <= jobs[i][0]){
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(idx != -1) include += dp[idx];

            dp[i] = max(dp[i-1], include);
        }

        return dp[n-1];
    }
};

