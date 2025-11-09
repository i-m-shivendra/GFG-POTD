#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        unordered_map<int, int> freq;

        // Count frequency of each element
        for (int x : arr) freq[x]++;

        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        // Remaining elements in stack have no NGFE -> -1 (already set)
        return res;
    }
};
