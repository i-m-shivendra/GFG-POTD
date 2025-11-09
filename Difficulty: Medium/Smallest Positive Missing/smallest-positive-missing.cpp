class Solution {
  public:
    int missingNumber(vector<int> &arr) {
         vector<int> nums(1000000, 0);
     int ans = 0;
     for(int i = 0; i < arr.size(); i++){
         if(arr[i] > 0){
         nums[arr[i]]++;
         }
         else{
             continue;
         }
     }
     for(int i =1; i < nums.size(); i++){
         if(nums[i] == 0){ 
             ans = i; 
             break;
         }
     }
     return ans;
    }
};