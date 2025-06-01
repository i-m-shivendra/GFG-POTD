class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        int count = 0;
        int i = 0;
        int j = 0;
        
        while(j < n){
            
            if(arr[j] == 0){
                count += 1;
            }
            
            while(count > k){
                if(arr[i] == 0)
                count -= 1;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
