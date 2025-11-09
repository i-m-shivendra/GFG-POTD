class Solution {
public:
    int numberOfWays(int n) {
        if(n == 0 || n == 1) return 1;

        int prev2 = 1; 
        int prev1 = 1; 
        int curr;

        for(int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
