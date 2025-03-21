//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int dp[100001];
    int solve(vector<int>& arr, int i, int n) {
        
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int taken = arr[i] + solve(arr,i+2,n);
        int skip = solve(arr,i+1,n);
        
        return dp[i] = max(taken,skip);
    }
    int maxValue(vector<int>& arr) {
        
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        int s1 = solve(arr,0,n-1);
        memset(dp,-1,sizeof(dp));
        int s2 = solve(arr,1,n);
        
        return max(s1,s2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends