class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        set <int> st;
        
        for(auto it : a){
            st.insert(it);
        }
        
        for(int i=0;i<b.size();i++){
            if(st.find(b[i]) != st.end()){
                ans.push_back(b[i]);
            }
            st.erase(b[i]);
        }
        return ans;
    }
};