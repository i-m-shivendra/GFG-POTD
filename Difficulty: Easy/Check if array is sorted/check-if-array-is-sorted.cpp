class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j]){
                    return false;
                }
            }
        }
        return true;
    }
};