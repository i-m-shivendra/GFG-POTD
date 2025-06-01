// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        
        set <int> st;
        
        for(int i=0;i<m;i++){
            st.insert(a[i]);
        }
        
        for(int j=0;j<n;j++){
            st.insert(b[j]);
        }
        
        return st.size();
    }
};