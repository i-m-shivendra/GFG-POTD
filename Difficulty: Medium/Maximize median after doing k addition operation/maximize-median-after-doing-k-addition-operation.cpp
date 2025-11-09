class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        if( n == 1 ) return arr[0] + k;
        int mid = (n-1)/2;
        
        sort(arr.begin(),arr.end());
        
        //edge case when mid is 0
        
        vector<int>prefSum(n);
        prefSum[0] = arr[0];
        for(int i=1;i<n;i++){
            prefSum[i] = prefSum[i-1] + arr[i];
        }
        int ans = 0;
        for(int i = n-1 ;i >=mid; i--){
            // can we make it till mid to i check
            int sum = prefSum[i] - prefSum[mid-1];
            int reqPts =(arr[i] * (i-mid+1)) - sum;
            
            if(reqPts <= k){
                ans = arr[i] + (k-reqPts) / (i-mid+1);
                
                if(n % 2 == 0 ) {
                    if(ans < arr[n/2]){
                        ans = (ans + arr[n/2])/2;
                    }
                }
                break;
            }
        }
        return ans;
    }
};