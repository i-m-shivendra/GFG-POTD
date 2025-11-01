class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for(int i=1;i<n;i++){
            int temp = arr[i];
            int j = i-1;
            
            while(j>=0 && arr[j]>temp){
                arr[j+1] = arr[j];
                j=j-1;
            }
            arr[j+1] = temp;
        }
    }
};