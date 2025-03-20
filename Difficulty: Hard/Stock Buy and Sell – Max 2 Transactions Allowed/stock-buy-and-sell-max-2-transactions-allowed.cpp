//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int buy1 = INT_MIN;
        int buy2 = INT_MIN;
        
        int sell1 = 0;
        int sell2 = 0;
        
        for(int price:prices){
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1+price);
            buy2 = max(buy2, sell1-price);
            sell2 = max(sell2, buy2+price);
        }
        
        return sell2;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends