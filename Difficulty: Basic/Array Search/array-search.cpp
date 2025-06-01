class Solution {
  public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
    }
};