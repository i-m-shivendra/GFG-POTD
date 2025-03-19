//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int solve(int i, bool buy, int n, int k, vector<int>&prices, 
    vector<vector<vector<int>>>&dp){
        if(i==n || k<=0) return 0;
        if(dp[i][k][buy]!=-1) return dp[i][k][buy];
        
        if(buy){
            return dp[i][k][buy]=max(-prices[i]+solve(i+1, 0, n, k, prices, dp), 
                                  solve(i+1, 1, n, k, prices, dp));
        }else{
            return dp[i][k][buy]=max(prices[i]+solve(i+1, 1, n, k-1, prices, dp), 
                                 solve(i+1, 0, n, k, prices, dp));
        }
    }
  
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(k+1, 
        vector<int>(2, -1)));
        return solve(0, 1, n, k, prices, dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends