//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // Your code here
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            } 
            else
            {
                if(st.empty())
                {
                    return false;
                }
                else if(s[i]==')' and st.top()=='(')
                {
                    st.pop();
                }
                else if(s[i]==']' and st.top()=='[')
                {
                    st.pop();
                }
                else if(s[i]=='}' and st.top()=='{')
                {
                    st.pop();
                } 
                else
                {
                    return false;
                }
            }
        }
        if(!st.empty())
            return false;
        else
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends