class Solution {
private:
     int v_c(string &s){
        int blnc = 0; 
        for(auto &x : s)
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' )
            ++blnc;
            else
            --blnc;
        
        return blnc;
    }
public:
    int countBalanced(vector<string>& arr) {
        unordered_map<int , int> mp;
        int cntBlncStr = 0;
        int sum = 0;
        mp[0] = 1;
        
        for(auto &s : arr){
            
            int blnc = v_c(s);
            sum += blnc;
            cntBlncStr += mp[sum];
            mp[sum]++;
        }
        
        return cntBlncStr;
    }
};
