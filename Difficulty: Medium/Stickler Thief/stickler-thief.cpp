//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n==1) return arr[0];
        
        vector<int> dp(n, -1);
        dp[0]=arr[0];
        dp[1]=arr[1];
        for(int i=2;i<n;i++){
            if(i==2){
                dp[i]=arr[i] + dp[i-2];
            }
            dp[i]=arr[i] + max(dp[i-2], dp[i-3]);
        }
        
        return max(dp[n-2],dp[n-1]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends