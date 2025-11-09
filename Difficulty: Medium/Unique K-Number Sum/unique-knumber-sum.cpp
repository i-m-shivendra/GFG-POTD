class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(int start, int n, int k, vector<int>& curr) {
        if(k == 0 && n == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(k == 0 || n < 0) return;

        for(int num = start; num <= 9; num++) {
            curr.push_back(num);
            backtrack(num + 1, n - num, k - 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(int n, int k) {
        vector<int> curr;
        backtrack(1, n, k, curr);
        return ans;
    }
};
