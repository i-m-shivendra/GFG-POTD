class Solution {
public:
    int longestSubarray(vector<int> &arr, int k) {
         int x=arr.size();
        int left =0;
        int right =0;
        unordered_map<int,int> mpp;
        vector<int> test(x);
        for(int i=0;i<arr.size();i++){
            if(arr[i]>k){
                test[i]=1;
            }else{
                test[i]=-1;
            }
        }
        int maxi =0;
        int presum =0;
        for(int i=0;i<arr.size();i++){
            presum+=test[i];
            if(presum>0){
                maxi=i+1;
            }
            if(mpp.find(presum-1)!=mpp.end()){
                maxi=max(maxi,i-mpp[presum-1]);
            }
            if(mpp.find(presum)==mpp.end()){
                mpp[presum]=i;
            }
        }
        return maxi;
    }
};