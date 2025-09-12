class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        return arr[n-1];
    }
};
