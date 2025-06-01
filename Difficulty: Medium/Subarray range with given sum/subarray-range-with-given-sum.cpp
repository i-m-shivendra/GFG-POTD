class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(mp.find(sum-tar) != mp.end()){
                count += mp[sum-tar];
            }
            mp[sum]++;
        }
        return count;
    }
};