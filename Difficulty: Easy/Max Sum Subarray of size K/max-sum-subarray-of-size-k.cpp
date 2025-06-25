class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        
        int sum = 0;
        
        for(int i=0;i<k;i++){
            sum += arr[i];
        }
        
        int j = 0;
        int ans = sum;
        for(int i=k;i<n;i++){
            sum += arr[i] - arr[j];
            ans = max(ans,sum);
            j++;
        }
        return ans;
    }
};