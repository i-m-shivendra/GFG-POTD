class Solution {
public:
    int longestSubarray(vector<int>& arr) {
         int n = arr.size();
    vector<int> nge(n, n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            nge[i] = st.top();
        }
        st.push(i);
    }
    vector<int>pge(n,-1);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty()&&arr[s.top()]<=arr[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            pge[i]=s.top();
        }
        s.push(i);
    }
      int result = 0;
    for (int i = 0; i < n; i++) {
        int len = nge[i] - pge[i] - 1; 
        if (arr[i] <= len) {
            result = max(result, len);
        }}
    return result;
    }
};
