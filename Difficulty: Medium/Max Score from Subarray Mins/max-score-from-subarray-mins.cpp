class Solution {
   public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int current_sum=0;
      int sum=INT_MIN;
      int maxi=0;
    for(int i=0;i<n-1;i++)
    {   
         current_sum=arr[i]+arr[i+1];
         if(current_sum>sum)
         { sum=current_sum;
            maxi=max(sum,maxi);

          }
         
    }
    return maxi;
        
    }
};